/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/15 18:37:08 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back_ast_node(t_ast **ast, t_ast *new)
{
	t_ast	*tmp;

	tmp = NULL;
	tmp = *ast;
	if (!*ast)
		*ast = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_tokens	*ft_lstnew_ast_node(char *content)
{
	t_tokens	*new_elem;

	new_elem = malloc (sizeof(t_ast));
	if (!new_elem)
		return (NULL);
	new_elem->type = 0;
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

void	build_tree(t_ast **ast, t_tokens **token)
{
	// int i = 0;
	// printf("Enter in build tree\n");
	// while (i < 1)
	// {
		if ((*token)->next->type != PIPE)
			parse_command(token, ast);
		else
			parse_pipe(token);
		// ast = (*ast).next;
		// ast = malloc(sizeof(t_ast));
		// ast add back
	// 	i++;
	// }
}

/////// PROTEGER TOUS LES MALLOCS !!!! ///////// 
