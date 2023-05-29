/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/29 19:02:59 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// Token is the list obtained after lexing.
// Tree is the list containing the tree.

void	build_tree(t_tokens **token, t_tree **tree)
{
	t_data_
	int	nb_token;

	nb_token = ft_lstsize(token);
	while (*token)
	{	
		if (is_special_type(*token)->type == 1)
			parse_special_type();
		else
			parse_word();
	}
}

void	build_tree(t_tokens **token, t_tree **tree)
{
	
	while (*token)
	{	
		if (is_special_type(*token)->type == 1)
			parse_special_type();
		else
			parse_word();
	}
}

// IS_LEAF : This function returns 1 if the token being parse is a leaf.
// int	is_leaf()
// {
// 	if ()
// 		return (1;)
// 	return (0);
// }


// void    parse_word(t_tokens **token, t_tree **tree)
// {}
