/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:33:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/29 19:01:33 by lduheron         ###   ########.fr       */
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
//								ENUM							//
//																//
//////////////////////////////////////////////////////////////////

enum e_type_exec
{
	COMMAND,
	PIPE,
	AND,
	OR,
	REDIRECTION
} ;

enum e_type_token
{
	N_DEF,
	WORD,
	O_PARENTHESIS,
	C_PARENTHESIS,
	PIPE_SIGN,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	AND_SIGN,
	OR_SIGN
} ;

//////////////////////////////////////////////////////////////////
//																//
//																//
//							STRUCTURES							//
//																//
//																//
//////////////////////////////////////////////////////////////////

typedef struct s_data_lexing				t_data_lexing;
typedef struct s_data_parsing				t_data_parsing;
typedef struct s_tokens						t_tokens;
typedef struct s_tree						t_tree;
typedef union u_tree_node_content			t_tree_node_content;
typedef struct s_leaf						t_leaf;
typedef struct s_branch						t_branch;

//////////////////////////////////////////////////////////////////
//																//
//						EXEC STRUCTURES							//
//																//
//////////////////////////////////////////////////////////////////

typedef struct s_cmd
{
	char	*argv;
	int		fd_in;
	int		fd_out;
}	t_cmd;

typedef struct s_pipe
{
	int				type;
	struct s_cmd	*cmd1;
	struct s_cmd	*cmd2;
}	t_pipe;

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

struct s_data_lexing {
	char	*line;
	int		pos;
	int		len;
};

struct	s_data_parsing {
	struct s_cmd	preceding_command;
	int				nb_token;
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


// The tree can contain two types of content : either it represents a simple
// command, in which case the active value is a t_leaf structure. The concept
// of a leaf signifies the end of a branch. Alternatively, it can represent
// a node, in which case it needs to be split into two branches : 
// the left branch and the right branch.

union u_tree_node_content
{
	struct t_leaf		leaf;
	struct t_branch		node;
};

struct	s_tree {
	u_tree_node_content	content;
	enum e_type_exec	type;
};

struct s_branch {
	struct s_tree	*left;
	struct s_tree	*right;
};

struct s_leaf {
	char	*arg;
};


// (this is not a structure that I use, its to silence some warnings
// when I only want to work n the lexing.)
//
// struct	s_tree {
// 	enum e_type_exec	type;
// };

//////////////////////////////////////////////////////////////////
//																//
//																//
//							PROTOTYPES 							//
//																//
//																//
//////////////////////////////////////////////////////////////////

// Main.c
int			main(int argc, char **argv);
void		ft_print_lst_token(t_tokens *token);

//////////////////////////////////////////////////////////////////
//																//
//                 	  	IN AST UTILS DIR   	                    //
//																//
//////////////////////////////////////////////////////////////////

// Ft_split.c
char		**ft_split(char const *s, char c);

// Is_something.c
int			ft_isalpha(int c);
int			is_space(char c);
int			is_sign(char c);
int			is_pipe(char c);

// Lexing_utils.c
char		*ft_strjoin(char *s1, char *s2);
int			int_strchr(const char *s, int start, int c);
int			get_content(char *dst, char *src, unsigned int size,
				unsigned int start);
char		*ft_strdup(char *src);

// Parsing_utils.c
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// Utils.c
int			ft_strlen(char *str);

//////////////////////////////////////////////////////////////////
//																//
//                   	  IN LEXING DIR              	        //
//																//
//////////////////////////////////////////////////////////////////

// Lexing.c
t_tokens	*add_new_token(char *content, int type);
int			find_type(t_data_lexing **data_lexing);
t_tokens	*which_new_token(t_data_lexing *data_lexing);
void		lexing(t_tokens **token, char **argv);

// New_token.c
t_tokens	*new_token(t_data_lexing *data_lexing, int type);
t_tokens	*new_token_word(t_data_lexing *data_lexing);
t_tokens	*new_token_parenthesis(t_data_lexing *data_lexing);
t_tokens	*new_token_single_quote(t_data_lexing *data_lexing);
t_tokens	*new_token_double_quote(t_data_lexing *data_lexing);

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
//                 		IN PARSING DIR   		                //
//																//
//////////////////////////////////////////////////////////////////

// Parsing.c
void		eat_token(t_tokens **tokens);
void		build_tree(t_tokens **token, t_tree **tree);
void		parse_word(t_tokens **token, t_tree **tree);


//////////////////////////////////////////////////////////////////
//																//
//              	IN STRUCTURES MANAGEMENT DIR   	            //
//																//
//////////////////////////////////////////////////////////////////

// Init_structures.c 
void		init_data_structure(t_data_lexing *data_lexing, char **argv);
void		init_token_structure(t_tokens **tokens);
// void		init_structures(t_tokens **tokens, t_tree **tree,
// 				char **argv);
// void		init_tree_structure(t_tree **tree);

// Free_structures.c
void		free_data_structure(t_data_lexing *data_lexing);
void		free_token_structure(t_tokens **tokens);
void		free_structures(t_tokens **tokens);
// void		free_tree_structure(t_tree **tree);
void		ft_lstclear(t_tokens **lst);

#endif
