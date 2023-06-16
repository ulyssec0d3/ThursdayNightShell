/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/17 00:09:13 by lduheron         ###   ########.fr       */
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

int	parsing(t_ast **ast, t_tokens **token)
{
	int	flag;

	flag = TRUE;
	while (*token != NULL)
	{
		if ((*token)->type != PIPE)
			flag = parse_command(ast, token);
		else
		{
			// if (*ast == NULL)
			// 	return (error);
			parse_pipe(ast, token);
		}
		if (flag != TRUE)
			return (flag);
	}
	return (flag);
}
