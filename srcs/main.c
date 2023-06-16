/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/17 00:12:11 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	t_tokens	*token;
	t_ast		*ast;

	token = NULL;
	ast = malloc(sizeof(t_ast));
	if (!ast)
		return (ERROR_MALLOC);
	ast = NULL;
	if (argc != 2)
		return (0);
	lexing(&token, argv);
	// if (token)
	// 	ft_print_lst_token(token);
	parsing(&ast, &token);
	print_ast(&ast);
	// free_structures(&tokens);
	// if (tokens)
	// 	free(tokens);
	free_ast(&ast);
	free(ast);
	return (0);
}
