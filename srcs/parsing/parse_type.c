/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:25:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/01 09:41:39 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_word(t_data_parsing *data_parsing, t_tokens **token,
			t_tree **tree)
{
	t_cmd	cmd;

	(void) tree;
	cmd.cmd = (*token)->content;
	data_parsing->preceding_cmd = cmd;
	eat_token(token);
	data_parsing->nb_token -= 1;
	printf("simple cmd : %s\n", cmd.cmd);
	// if ((*token)->next && (*token)->next->type != 0)
	// {
	// 	if (is_leaf(token) == 0)
	// 		data_parsing->preceding_cmd = cmd;
	// 	else
	// 		add_to_tree(tree, cmd);
	// 	eat_token(token);
	// }
}

// t_tree_node_content
void	parse_pipe(t_data_parsing *data_parsing, t_tokens **token)
{
	t_pipe				pipe;
	// t_tree_node_content	node;

	pipe.cmd1 = &data_parsing->preceding_cmd;
	eat_token(token);
	pipe.cmd2->cmd = (*token)->content;
	eat_token(token);
	data_parsing->nb_token -= 2;
	// node.leaf = pipe;
	printf("pipe.cmd1 : %s, pipe.cmd2 : %s\n", pipe.cmd1->cmd, pipe.cmd2->cmd);
	// return (node);
}
