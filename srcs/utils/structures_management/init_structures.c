/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:34:54 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/18 15:11:22 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data_structure(t_data *data, char **argv)
{
	data->line = NULL;
	data->line = ft_strjoin(data->line, argv[1]);
	data->len = ft_strlen(data->line);
	data->pos = 0;
}

// INIT TOKEN STRUCTURE : Initialize the elements of a t_tokens structure.

void	init_token_structure(t_tokens **token)
{
	ft_lstadd_back(token, ft_lstnew(0));
	(*token)->type = N_DEF;
}

void	init_structures(t_data *data, t_tokens **tokens, t_tree **tree,
	char **argv)
{
	init_data_structure(data, argv);
	init_token_structure(tokens);
	// init_tree_structure(&tree);
	(void)tree;
}

// void	init_tree_structure(t_tree **tree)
// {
// 	ft_lstadd_back(tree, ft_lstnew);
// 	tree->next = NULL;
// }
