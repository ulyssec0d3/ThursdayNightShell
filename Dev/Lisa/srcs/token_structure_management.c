/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_structure_management.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:23:46 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/21 20:40:53 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

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

// FREE TOKEN STRUCTURE : Free the elements of a t_tokens structure.

void	free_token_structure(t_tokens **tokens)
{
	(*tokens)->type = 0;
	ft_lstclear(tokens);
}

// INIT TOKEN STRUCTURE : Initialize the elements of a t_tokens structure.

void	init_token_structure(t_tokens **tokens)
{
	ft_lstadd_back(tokens, ft_lstnew(0));
	(*tokens)->type = N_DEF;
}
