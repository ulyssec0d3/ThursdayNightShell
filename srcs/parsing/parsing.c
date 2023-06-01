/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/01 09:23:50 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data_parsing(t_data_parsing *data_parsing, t_tokens **token)
{
	data_parsing->nb_token = ft_lstsize(*token);
}

// Token is the list obtained after lexing.
// Tree is the list containing the tree.

void	build_tree(t_tokens **token, t_tree **tree)
{
	t_data_parsing	data_parsing;

	init_data_parsing(&data_parsing, token);
	while (data_parsing.nb_token > 0)
	{
		if ((*token)->type == 1)
			parse_word(&data_parsing, token, tree);
		else
			parse_pipe(&data_parsing, token);
	}
}
