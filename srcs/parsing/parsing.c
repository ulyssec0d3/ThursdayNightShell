/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/14 15:26:09 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	build_tree(t_tokens **token, t_root **tree)
{
	printf("Enter in build tree\n");
	// if ((*token)->next->type != 2)
	parse_command(token, tree);
	// while ((*token))
	// {
		// else
		// 	parse_pipe(&data_parsing, token);
	// }
}

/////// PROTEGER TOUS LES MALLOCS !!!! ///////// 
