/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:33:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/29 14:20:18 by ulevallo         ###   ########.fr       */
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

////////////////////// ENUM //////////////////////

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

////////////////////// STRUCTURES //////////////////////

typedef struct s_data {
	char	*line;
	int		pos;
	int		len;
}			t_data;

typedef struct s_tokens
{
	enum e_type_token	type;
	int					len;
	char				*content;
	struct s_tokens		*next;
}	t_tokens;

typedef struct s_tree
{
	char	type;
	char	content;
}	t_tree;

////////// EXEC STRUCTURES //////////////////

typedef struct s_cmd
{
	char	*argv;
	int		fd_in;
	int		fd_out;
}	t_cmd;

typedef struct s_pipe
{
	int		type;
	char	*cmd1;
	char	*cmd2;
}	t_pipe;

// typedef struct s_redirections
// {
// 	int		type;
// 	char	*cmd1;
// 	char	*cmd2;
// 	int		mode;
// 	int		fd;
// }	t_redirections;

////////////////////// PROTOTYPES //////////////////////

// Main.c
int			main(int argc, char **argv, char **env);

////////////////////// IN AST UTILS DIR //////////////////////
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

////////////////////// IN LEXING DIR //////////////////////
// Lexing.c
t_tokens	*add_new_token(char *content, int type);
int			find_type(t_data **data);
t_tokens	*which_new_token(t_data *data);
void		lexing(t_data *data, t_tokens **token);

// New_token.c
t_tokens	*new_token(t_data *data, int type);
t_tokens	*new_token_word(t_data *data);
t_tokens	*new_token_parenthesis(t_data *data);
t_tokens	*new_token_single_quote(t_data *data);
t_tokens	*new_token_double_quote(t_data *data);

// Parenthesis_management.c
int			cpt_parenthesis(char c);
int			is_parenthesis(char c);
int			parenthesis_management(t_data *data);

// Quote_management.c
int			is_double_quote(char c);
int			is_single_quote(char c);
int			is_quote(char c);
int			single_quote_management(t_data *data);
int			double_quote_management(t_data *data);

////////////////////// IN LIST UTILS DIR //////////////////////
// List_utils.c
void		ft_lstadd_back(t_tokens **lst, t_tokens *new);
void		ft_lstadd_front(t_tokens **lst, t_tokens *new);
int			ft_lstsize(t_tokens *lst);
t_tokens	*ft_lstnew(char *content);
t_tokens	*ft_lstlast(t_tokens *lst);

////////////////////// IN PARSING DIR //////////////////////
// Parsing.c
void		eat_token(t_tokens **tokens);
void		build_tree(t_tokens **token, t_tree **tree);
void		parse_word(t_tokens **token, t_tree **tree);

////////////////////// IN STRUCTURES MANAGEMENT DIR //////////////////////
// Init_structures.c
void		init_data_structure(t_data *data, char **argv);
void		init_token_structure(t_tokens **tokens);
void		init_structures(t_data *data, t_tokens **tokens, t_tree **tree,
				char **argv);
// void		init_tree_structure(t_tree **tree);

// Free_structures.c
void		free_data_structure(t_data *data);
void		free_token_structure(t_tokens **tokens);
void		free_structures(t_data *data, t_tokens **tokens);
// void		free_tree_structure(t_tree **tree);
void		ft_lstclear(t_tokens **lst);

#endif
