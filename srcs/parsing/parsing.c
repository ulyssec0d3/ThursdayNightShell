/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/14 11:40:30 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	build_tree(t_tokens **token, t_root **tree)
// {
// 	while ((*token))
// 	{
// 		if ((*token)->next->type != 1)
// 			parse_command(token, tree);
// 		else
// 			parse_pipe(&data_parsing, token);
// 	}
// }

// void	print_ast(t_root **tree)
// {
// 	int	i; // nb nodes

// 	i = 0;
// 	while (ast->next)
// 	{
// 		printf();
// 	}
// }

// int j;

// j = 0;
// while (argument[j])
// {
// 	printf("Argument[%i] : %s\n", j, argument[j]);
// 	j++;
// }
// j = 0;
// while (redirections[j])
// {
// 	redirections[j] = 
// 	printf("\n", redirections_type[j]);
// 	j++;
// }