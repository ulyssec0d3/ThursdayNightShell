/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/17 14:15:35 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_tokens	*token;
	t_ast		*ast;

	if (argc != 2)
		return (0);
	ast = malloc(sizeof(t_ast));
	if (!ast)
		return (ERROR_MALLOC);
	ast = NULL;
	token = NULL;
	lexing(&token, argv);
	parsing(&ast, &token);
	print_ast(&ast);
	get_env(env);
	expand(&ast);
	free_ast(&ast);
	free(ast);
	return (0);
}
