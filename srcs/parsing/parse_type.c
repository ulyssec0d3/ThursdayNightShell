/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:25:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/13 16:32:09 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_arg(t_tokens **token, t_command_node *cmd)
{
	int	i_arg;
	int	i_red;

	i_arg = 0;
	i_red = 0;
	while ((*token)->type != 1)
	{
		if ((*token)->type == WORD)
			cmd->argument[i_arg] = (*token)->content; // malloc attention
		else
		{
			cmd->redirections[i_red] = (*token)->content;
			cmd->redirections_type[i_red] = (*token)->type;
			cmd->argument[i_arg] = (*cmd).redirections[i_red];
			i_red++;
		}
		i_arg++;
		eat_token(token);
	}
}

// faire une fonction qui compte le nombre d'arg a malloc pour parse command.

void	parse_command(t_tokens **token, t_root **tree)
{
	t_command_node	cmd;

	(void) tree;
	cmd.redirections = NULL;
	cmd.cmd = (*token)->content;
	eat_token(token);
	get_arg(token, &cmd);
}

// void	parse_pipe(t_tokens **token, t_root **tree)
// {
// 	t_operator_node	node;

// 	node.type = PIPE_;
// 	node.cmd1 = tree;
// 	eat_token(token);
// 	node.cmd2 = parse_command(token, tree);
// }
