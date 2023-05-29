/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:09:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/29 17:16:09 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear(t_tokens **lst)
{
	t_tokens	*tmp;

	while (*lst && lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	free_structures(t_data *data, t_tokens **tokens)
{
	free_data_structure(data);
	free_token_structure(tokens);
	// free_tree_structure(&tree);
}

void	free_data_structure(t_data *data)
{
	free(data->line);
}

// FREE TOKEN STRUCTURE : Free the elements of a t_tokens structure.

void	free_token_structure(t_tokens **tokens)
{
	t_tokens	*tmp;

	while (*tokens && tokens)
	{
		tmp = (*tokens)->next;
		free((*tokens)->content);
		free(*tokens);
		*tokens = tmp;
	}
}

// void    free_tree_structure(t_tree **tree)
// {}
