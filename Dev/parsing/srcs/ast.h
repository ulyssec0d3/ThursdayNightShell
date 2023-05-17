/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:33:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/17 18:19:52 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../utils/ast_utils/ast_utils.h"
# include "../utils/list_utils/list_utils.h"
# include "../utils/structures_management/structures_management.h"

# include "./lexing/lexing.h"
// # include "./parsing/parsing.h"
// # include "../expand/expand.h"

enum e_type_exec
{
	COMMAND,
	PIPE,
	AND,
	OR,
	REDIRECTION
} ;

// # define 
// >
// >>
// <
//  cmd
//  open close
//  "
//  '"

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

typedef struct s_cmd
{
	char	*argv;
	int		fd_in;
	int		fd_out;
}	t_cmd;

// Main.c
int			main(int argc, char **argv);

#endif
