/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operator_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:07:06 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 23:37:34 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_command(t_cmd_lst **cmd_lst, t_tokens **token)
{
	t_cmd_lst	*tmp;
	int			flag;

	tmp = malloc(sizeof(t_cmd_lst));
	if (!tmp)
		return (ERROR_MALLOC);
	tmp->type = CMD_NODE;
	tmp->next = NULL;
	tmp->cmd_node = NULL;
	flag = init_cmd_node(token, tmp);
	if (flag != SUCCESS)
		return (flag);
	get_arg(token, tmp->cmd_node);
	ft_lstadd_back_cmd_lst_node(cmd_lst, tmp);
	return (SUCCESS);
}

int	parse_pipe(t_cmd_lst **cmd_lst, t_tokens **token)
{
	t_cmd_lst	*tmp;

	tmp = malloc(sizeof(t_cmd_lst));
	tmp->type = PIPE_NODE;
	tmp->cmd_node = NULL;
	tmp->next = NULL;
	eat_token(token);
	ft_lstadd_back_cmd_lst_node(cmd_lst, tmp);
	return (SUCCESS);
}
