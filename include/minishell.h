/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:33:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/17 19:48:35 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

//////////////////////////////////////////////////////////////////
//																//
//							FLAG ERROR							//
//																//
//////////////////////////////////////////////////////////////////

# define TRUE 1
# define ERROR_MALLOC -1

//////////////////////////////////////////////////////////////////
//																//
//								ENUM							//
//																//
//////////////////////////////////////////////////////////////////

enum e_type_exec
{
	COMMAND_NODE,
	PIPE_NODE
} ;

enum e_type_token
{
	N_DEF,
	WORD,
	PIPE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	SIMPLE_IN, // < infile
	SIMPLE_OUT, // > Append
	DOUBLE_IN, // << limiter // \n >> Truncate
	DOUBLE_OUT
} ;

//////////////////////////////////////////////////////////////////
//																//
//																//
//						STRUCTURES								//
//																//
//																//
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
//																//
//						EXEC STRUCTURES							//
//																//
//////////////////////////////////////////////////////////////////

// typedef struct s_pipe
// {
// 	struct s_cmd		*cmd1;
// 	struct s_cmd		*cmd2;
// }	t_pipe;

// typedef struct s_redirections
// {
// 	int		type;
// 	char	*cmd1;
// 	char	*cmd2;
// 	int		mode;
// 	int		fd;
// }	t_redirections;

//////////////////////////////////////////////////////////////////
//																//
//						DATA STRUCTURES							//
//																//
//////////////////////////////////////////////////////////////////

typedef struct s_data_lexing				t_data_lexing;
typedef struct s_tokens						t_tokens;

struct s_data_lexing {
	char	*line;
	int		pos;
	int		len;
};

struct s_tokens {
	enum e_type_token	type;
	int					len;
	char				*content;
	struct s_tokens		*next;
};

//////////////////////////////////////////////////////////////////
//																//
//						TREE STRUCTURES							//
//																//
//////////////////////////////////////////////////////////////////

// Operator node represents a logical operator for instance |
// left, right subexpression, operator type.
// Command node : the node represents a simple command.
// Root node : root node, where I start my program.

typedef struct s_command_node				t_command_node;
typedef struct s_ast						t_ast;

struct s_command_node {
	char	*cmd;
	char	**argument;
	char	**redirections;
	int		*redirections_type;
};

struct s_ast {
	enum e_type_exec			type;
	t_command_node				*cmd;
	t_ast						*next;
};

// Expand_structures
typedef struct s_env_lst
{
	char				*content;
	struct s_env_lst	*next;
}	t_env_lst;

typedef struct s_expand
{
	char		*new_arg;
	int			i;
	int			j;
}		t_expand;

//////////////////////////////////////////////////////////////////
//																//
//																//
//							PROTOTYPES 							//
//																//
//																//
//////////////////////////////////////////////////////////////////

// Main.c
int			main(int argc, char **argv, char **env);

// Print_ast.c
void		ft_print_lst_token(t_tokens *token);
void		print_cmd_node(t_command_node *cmd);
void		print_ast(t_ast **ast);

//////////////////////////////////////////////////////////////////
//																//
//              			IN EXPAND DIR   		            //
//																//
//////////////////////////////////////////////////////////////////

// Env.c
int			expand(t_ast **ast, char **env);
void		print_env_lst(t_env_lst **env_lst);
int			get_size_env(char **env, t_env_lst **env_lst);
void		ft_lstadd_back_env_lst(t_env_lst **env_lst, t_env_lst *new);

// Expand.c
char		*extract_value(char *str);
void		substitute_value(t_ast *tree);
int			search_substitute_variable(char *str);


//////////////////////////////////////////////////////////////////
//																//
//                   	  IN LEXING DIR              	        //
//																//
//////////////////////////////////////////////////////////////////

// Lexing_type.c
t_tokens	*lexing_double_quote(t_data_lexing *data_lexing);
t_tokens	*lexing_redirection(t_data_lexing *data_lexing, int type,
				int size_redirection);
t_tokens	*lexing_single_quote(t_data_lexing *data_lexing);
t_tokens	*lexing_word(t_data_lexing *data_lexing);

// Lexing.c
t_tokens	*add_new_token(char *content, int type);
t_tokens	*new_token(t_data_lexing *data_lexing, int type, int size);
int			find_type(t_data_lexing **data_lexing);
t_tokens	*which_new_token(t_data_lexing *data_lexing);
void		lexing(t_tokens **token, char **argv);

// Parenthesis_management.c
int			cpt_parenthesis(char c);
int			is_parenthesis(char c);
int			parenthesis_management(t_data_lexing *data_lexing);

// Quote_management.c
int			is_double_quote(char c);
int			is_single_quote(char c);
int			is_quote(char c);
int			single_quote_management(t_data_lexing *data_lexing);
int			double_quote_management(t_data_lexing *data_lexing);

// Utils.c
int			get_content(char *dst, char *src, unsigned int size,
				unsigned int start);
int			is_redirection(t_data_lexing *data_lexing);
int			int_strchr(const char *s, int start, int c);

//////////////////////////////////////////////////////////////////
//																//
//                 		IN PARSING DIR   		                //
//																//
//////////////////////////////////////////////////////////////////

// Parse_operator_type.c
void		parse_pipe(t_ast **ast, t_tokens **token);

// Parse_cmd_node.c
int			init_cmd_tab(t_ast *ast, int i_arg, int i_red);
int			init_command_node(t_tokens **token, t_ast *ast);
void		get_arg(t_tokens **token, t_command_node *cmd);
int			parse_command(t_ast **ast, t_tokens **token);

// Parsing.c
void		ft_lstadd_back_ast_node(t_ast **ast, t_ast *new);
t_tokens	*ft_lstnew_ast_node(char *content);
int			parsing(t_ast **ast, t_tokens **token);

// Utils.c
void		eat_token(t_tokens **tokens);
void		free_ast(t_ast **ast);
void		free_command_node(t_command_node *cmd);

//////////////////////////////////////////////////////////////////
//																//
//                 	 	 IN UTILS DIR   	                    //
//																//
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
//																//
//                 	  	IN AST UTILS DIR   	                    //
//																//
//////////////////////////////////////////////////////////////////

// Ft_strjoin.c
char		*ft_strjoin(char *s1, char *s2);

// Is_something.c
int			is_alpha(int c);
int			is_dollar(char c);
int			is_pipe(char c);
int			is_sign(char c);
int			is_space(char c);

// Libft_utils.c
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *src);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(char *str);

//////////////////////////////////////////////////////////////////
//																//
//               	  	IN LIST UTILS DIR   	                //
//																//
//////////////////////////////////////////////////////////////////

// List_utils.c
void		ft_lstadd_back(t_tokens **lst, t_tokens *new);
void		ft_lstadd_back2(t_tokens *lst, t_tokens new);
void		ft_lstadd_front(t_tokens **lst, t_tokens *new);
int			ft_lstsize(t_tokens *lst);
t_tokens	*ft_lstnew(char *content);
t_tokens	*ft_lstlast(t_tokens *lst);

//////////////////////////////////////////////////////////////////
//																//
//              	IN STRUCTURES MANAGEMENT DIR   	            //
//																//
//////////////////////////////////////////////////////////////////

// Init_structures.c 
void		init_data_lexing_structure(t_data_lexing *data_lexing, char **argv);

// Free_structures.c
void		free_token_structure(t_tokens **tokens);
void		free_structures(t_tokens **tokens);
void		ft_lstclear(t_tokens **lst);

#endif
