/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/18 16:55:08 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_tokens	*token;
	t_ast		*ast;

	if (argc != 2)
		return (0);
	lexing(&token, argv);
	if (token)
		ft_print_lst_token(token);
	ast = malloc(sizeof(t_ast));
	if (!ast)
		return (ERROR_MALLOC);
	ast = NULL;
	token = NULL;
	// parsing(&ast, &token);
	// print_ast(&ast);
	// get_env(env);
	(void)env;
	// (void)argv;
	// expand(&ast, env);
	free_ast(&ast);
	free(ast);
	return (0);
}
