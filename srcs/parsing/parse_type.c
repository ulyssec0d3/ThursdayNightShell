/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:25:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/14 16:36:45 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_arg(t_tokens **token, t_command_node *cmd)
{
	int	i_arg;
	int	i_red;
	int	i = 0;

	i_arg = 0;
	i_red = 0;
	printf("Enter in get arg\n");
	// printf("In get arg, token content : %s, token type : %i\n", (*token)->content, (int)(*token)->type);
	// while (token && (*token)->type != PIPE)
	while (i < 3)
	{
		if ((*token)->type == WORD)
		{
			// cmd->argument[i_arg] = malloc(sizeof (char *) * ((*token)->len + 1));
			cmd->argument[i_arg] = ft_strdup((*token)->content);
			i_arg++;
		}
		else
		{
			cmd->redirections[i_red] = ft_strdup((*token)->content);
			cmd->redirections_type[i_red] = (int *)((*token)->type);
			i_red++;
		}
		eat_token(token);
		i++;
	}
}

// faire une fonction qui compte le nombre d'arg a malloc pour parse command.

void	parse_command(t_tokens **token, t_root **tree)
{
	t_command_node	cmd;

	(void) tree;
	cmd.argument = NULL;
	printf("Enter in parse command\n");
	init_command_node(token, &cmd);
	cmd.cmd = ft_strdup((*token)->content);
	eat_token(token);
	get_arg(token, &cmd);
	print_cmd_node(&cmd);
	free_command_node(&cmd);
}

// void	parse_pipe(t_tokens **token, t_root **tree)
// {
// 	t_operator_node	node;

// 	node.type = PIPE;
// 	node.cmd1 = tree;
// 	eat_token(token);
// 	node.cmd2 = parse_command(token, tree);
// }

// void	init_root(t_tree **root)
// {

// }