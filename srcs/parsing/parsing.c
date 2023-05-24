/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/18 15:04:52 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// This function free the token after we worked on it
// and set the pointer to the next token

// void	eat_token(t_tokens **tokens)
// {
// 	t_tokens	*tmp;

// 	tmp = *tokens;
// 	if (tokens == NULL)
// 		return ;
// 	*tmp = tmp->next;
// 	// lst clear(token);
// 	free(tmp);
// }

// Token is the list after lexing.
// Tree is the list containing the tree.

// void	build_tree(t_tokens **token, t_tree **tree)
// {
// 	while (*token)
// 	{
// 		if (is_special_type(*token)->type == 1)
// 			parse_special_type();
// 		else
// 			parse_word();
// 	}
// }

// void    parse_word(t_tokens **token, t_tree **tree)
// {}
