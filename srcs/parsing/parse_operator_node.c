/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operator_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:07:06 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/19 18:14:45 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_command(t_ast **ast, t_tokens **token)
{
	t_ast	*tmp;
	int		flag;

	// printf("Enter in parse command\n");
	tmp = malloc(sizeof(t_ast));
	if (!tmp)
		return (ERROR_MALLOC);
	tmp->type = COMMAND_NODE;
	tmp->next = NULL;
	tmp->cmd_node = NULL;
	flag = init_command_node(token, tmp);
	if (flag != SUCCESS)
		return (flag);
	get_arg(token, tmp->cmd_node);
	ft_lstadd_back_ast_node(ast, tmp);
	return (SUCCESS);
}

void	parse_pipe(t_ast **ast, t_tokens **token)
{
	t_ast	*tmp;

	// printf("Enter parse pipe\n");
	tmp = malloc(sizeof(t_ast));
	tmp->type = PIPE_NODE;
	tmp->cmd_node = NULL;
	tmp->next = NULL;
	eat_token(token);
	ft_lstadd_back_ast_node(ast, tmp);
}
