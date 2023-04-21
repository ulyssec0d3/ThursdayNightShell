/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:33:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/21 21:12:18 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# define N_DEF 0
# define REDIRECTION 1
# define PARENTHESIS 2
# define PIPE 3
# define SINGLE_QUOTE 4

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../utils/token_utils/token_utils.h"
# include "../utils/list_utils/list_utils.h"

typedef struct s_pipe {
	int		type;
	char	*cmd1;
	char	*cmd2;
}	t_pipe;

typedef struct s_redirections {
	int		type;
	char	*cmd1;
	char	*cmd2;
	int		mode;
	int		fd;
}	t_redirections;

// Lexing.c
int		create_new_token(t_tokens **token, char *line, int i);
void	lexing(t_tokens **token, char *line);

// Main.c
int		main(int argc, char **argv);

// Parenthesis_management.c
int		cpt_parenthesis(char c);
int		is_parenthesis(char c);

// Token_structure_management.c
void	ft_lstclear(t_tokens **lst);
void	free_token_structure(t_tokens **tokens);
void	init_token_structure(t_tokens **tokens);

// Quote_management.c
int		is_double_quote(char c);
int		is_single_quote(char c);
int		is_quote(char c);

#endif
