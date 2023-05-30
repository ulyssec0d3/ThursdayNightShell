/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/30 12:14:48 by lduheron         ###   ########.fr       */
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
	t_data_parsing	data_parsing;

	init_data_parsing_structure(token);
	while (data_parsing->nb_token > 0)
	{
		if ((*token)->type == 1)
			
		else
			parse_special_type();
	}
}

// IS_LEAF : This function returns 1 if the token being parse is a leaf.
int	is_leaf(t_token **token)
{
	if ()
		return (1);
	return (0);
}

void	parse_word(t_tokens **token, t_tree **tree)
{
	typedef struct cmd;

	cmd = NULL;
	if (token.next->type && token.next->type != 0)
	{
		if (is_leaf == 0)
			data_parsing->precedent_command = cmd;
	}
}

void	init_data_parsing(t_data_parsing **data_parsing)
{
	data_parsing->nb_token = ft_lstsize(token);
}