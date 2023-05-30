/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:34:54 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/29 20:11:10 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data_lexing_structure(t_data_lexing *data_lexing, char **argv)
{
	data_lexing->line = NULL;
	data_lexing->line = ft_strjoin(data_lexing->line, argv[1]);
	data_lexing->len = ft_strlen(data_lexing->line);
	data_lexing->pos = 0;
}

// INIT TOKEN STRUCTURE : Initialize the elements of a t_tokens structure.

// void	init_token_structure(t_tokens **token)
// {
// 	*token = ft_lstnew(0);
// 	(*token)->type = N_DEF;
// }

// void	init_structures(t_data_lexing *data_lexing, t_tokens **tokens, t_tree **tree,
// 	char **argv)
// {
// 	init_data_lexing_structure(data_lexing, argv);
// 	(void)tree;
// 	(void)tokens;
// }

// void	init_tree_structure(t_tree **tree)
// {
// 	ft_lstadd_back(tree, ft_lstnew);
// 	tree->next = NULL;
// }
