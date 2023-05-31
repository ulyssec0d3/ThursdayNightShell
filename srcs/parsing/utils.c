/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:31:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/31 16:40:32 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// EAT_TOKEN : This function free the token after we worked on it
// and set the pointer to the next token

void	eat_token(t_tokens **tokens)
{
	t_tokens	*tmp;

	tmp = *tokens;
	if (tokens == NULL)
		return ;
	*tmp = tmp->next;
	// lst clear(token);
	free(tmp);
}

// IS_LEAF : This function returns 1 if the token being parse is a leaf.
int	is_leaf(t_tokens **token)
{
	if (!token->next)
		return (1);
	return (0);
}
