/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 23:20:03 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back_cmd_lst_node(t_cmd_lst **cmd_lst, t_cmd_lst *new)
{
	t_cmd_lst	*tmp;

	tmp = NULL;
	tmp = *cmd_lst;
	if (!*cmd_lst)
		*cmd_lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int	parsing(t_cmd_lst **cmd_lst, t_tokens **token)
{
	int	flag;

	flag = SUCCESS;
	while (*token != NULL)
	{
		if ((*token)->type != PIPE)
			flag = parse_command(cmd_lst, token);
		else
			flag = parse_pipe(cmd_lst, token);
		if (flag != SUCCESS)
			return (flag);
	}
	return (flag);
}
