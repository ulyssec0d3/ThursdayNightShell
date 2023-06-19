/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/19 13:11:39 by lduheron         ###   ########.fr       */
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

int	parsing(t_ast **ast, t_tokens **token)
{
	int	flag;

	flag = SUCCESS;
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
		if (flag != SUCCESS)
			return (flag);
	}
	return (flag);
}
