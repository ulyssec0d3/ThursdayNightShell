/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:33:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 17:52:13 by ulevallo         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

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
	SIMPLE_IN,
	SIMPLE_OUT,
	DOUBLE_IN,
	DOUBLE_OUT,
} ;

enum e_error
{
	SUCCESS,
	ERROR_MALLOC,
	ERROR_SYNTAX
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
//						DATA STRUCTURES							//
//																//
//////////////////////////////////////////////////////////////////

typedef struct s_data_lexing				t_data_lexing;
typedef struct s_tokens						t_tokens;

struct s_data_lexing {
	int		flag;
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
typedef struct s_cmd_lst					t_cmd_lst;

struct s_command_node {
	char	**argument;
	int		**argument_subst;
	char	**redir;
	int		*redir_type;
	int		*redir_sub;
};

struct s_cmd_lst {
	enum e_type_exec			type;
	t_command_node				*cmd_node;
	t_cmd_lst					*next;
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
int			main(int argc, char **argv, char **env, char **env);
void		check_line(t_data_lexing *data_lexing, char *str);

// Print_cmd_lst.c
void		ft_print_lst_token(t_tokens *token);
void		print_cmd_node(t_command_node *cmd);
void		print_cmd_lst(t_cmd_lst **cmd_lst);

//////////////////////////////////////////////////////////////////
//																//
//              			IN EXPAND DIR   		            //
//																//
//////////////////////////////////////////////////////////////////

// Env.c
int			expand(t_cmd_lst **cmd_lst, char **env);
void		print_env_lst(t_env_lst **env_lst);
int			get_size_env(char **env, t_env_lst **env_lst);
void		ft_lstadd_back_env_lst(t_env_lst **env_lst, t_env_lst *new);

// Expand.c
char		*extract_value(char *str);
void		substitute_value(t_cmd_lst *tree);
int			search_substitute_variable(char *str);

//////////////////////////////////////////////////////////////////
//																//
//                   	  IN LEXING DIR              	        //
//																//
//////////////////////////////////////////////////////////////////

// Error_syntax.c
void		check_syntax(t_tokens **tokens);

// Lexing_type.c
t_tokens	*lexing_double_quote(t_data_lexing *data_lexing);
t_tokens	*lexing_redirection(t_data_lexing *data_lexing, int type,
				int size_redirection);
t_tokens	*lexing_single_quote(t_data_lexing *data_lexing);
t_tokens	*lexing_word(t_data_lexing *data_lexing, int type);
t_tokens	*which_new_token(t_data_lexing *data_lexing);

// Lexing.c
t_tokens	*add_new_token(char *content, int type);
t_tokens	*new_token(t_data_lexing *data_lexing, int type, int size);
int			find_type(t_data_lexing **data_lexing);
void		lexing(t_tokens **token, char **argv);
t_tokens	*new_token_pipe(void);

// Parenthesis_management.c
int			cpt_parenthesis(char c);
int			is_parenthesis(char c);
int			parenthesis_management(t_data_lexing *data_lexing);

// Quote_management.c
int			is_double_quote(char c);
int			is_single_quote(char c);
int			is_quote(char c);
int			double_quote_management(char *line, int start);
int			single_quote_management(char *line, int start);

// Utils.c
int			get_content(char *dst, char *src, unsigned int size,
				unsigned int start);
int			is_redirection(t_data_lexing *data_lexing);
int			is_word(t_data_lexing *data_lexing);
int			int_strchr(const char *s, int start, int c);
int			is_metacharacter(char c);

//////////////////////////////////////////////////////////////////
//																//
//                 		IN PARSING DIR   		                //
//																//
//////////////////////////////////////////////////////////////////

// Parse_operator_type.c
void		parse_pipe(t_cmd_lst **cmd_lst, t_tokens **token);
int			parse_command(t_cmd_lst **cmd_lst, t_tokens **token);

// Init_command_node.c
void		set_command_node_to_null(t_command_node *cmd_node);
int			init_arg_tab(t_cmd_lst *cmd_lst, int i_arg);
int			init_redir_tab(t_cmd_lst *cmd_lst, int i_redir);
int			init_command_node(t_tokens **token, t_cmd_lst *cmd_lst);
int			is_substitutable(char *str);

// Get_arg.c
int			fill_arg(t_command_node *cmd_node, char *content, int i);
int			fill_redirection(t_command_node *cmd_node, char *content,
				int type, int i);
void		get_arg(t_tokens **token, t_command_node *cmd);

// Parsing.c
void		ft_lstadd_back_cmd_lst_node(t_cmd_lst **cmd_lst, t_cmd_lst *new);
t_tokens	*ft_lstnew_cmd_lst_node(char *content);
int			parsing(t_cmd_lst **cmd_lst, t_tokens **token);

// Utils.c
void		eat_token(t_tokens **tokens);
void		free_cmd_lst(t_cmd_lst **cmd_lst);
void		free_command_node(t_command_node *cmd);

//////////////////////////////////////////////////////////////////
//																//
//                 	 	 IN UTILS DIR   	                    //
//																//
//////////////////////////////////////////////////////////////////

// Error_management.c
void		free_data_lexing(t_data_lexing *data_lexing);
void		error_in_lexing(t_data_lexing *data_lexing, int code);
void		error_syntax(t_tokens **tokens);

//////////////////////////////////////////////////////////////////
//																//
//                 	  	IN cmd_lst UTILS DIR   	                    //
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
int			is_number(int c);

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
int			ft_lstsize(t_tokens *lst);
t_tokens	*ft_lstnew(char *content);

//////////////////////////////////////////////////////////////////
//																//
//              	IN STRUCTURES MANAGEMENT DIR   	            //
//																//
//////////////////////////////////////////////////////////////////

////////////////////// IN STRUCTURES MANAGEMENT DIR //////////////////////
// Init_structures.c
void		init_data_lexing_structure(t_data_lexing *data_lexing, char **argv);
void		init_token_structure(t_tokens **tokens);
void		init_structures(t_data *data, t_tokens **tokens, t_tree **tree,
				char **argv);
// void		init_tree_structure(t_tree **tree);

// Free_structures.c
void		free_token_structure(t_tokens **tokens);
void		free_structures(t_tokens **tokens);
void		ft_lstclear(t_tokens **lst);

#endif
