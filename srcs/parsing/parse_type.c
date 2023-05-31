/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:25:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/31 17:17:25 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_word(t_tokens **token, t_tree **tree)
{
	t_cmd	cmd;

	cmd = NULL;
	if (token.next && token.next->type != 0)
	{
		if (is_leaf(cmd) == 0)
			data_parsing->precedent_cmd = cmd;
		else
			add_to_tree(tree, cmd);
		eat_token(token);
	}
}

t_tree_node_content	parse_pipe(t_tokens *token, t_data_parsing *data_parsing)
{
	union t_tree_node_content	node;
	t_pipe						pipe;

	pipe = NULL;
	pipe->type = PIPE;
	pipe->cmd1 = data_parsing->preceding_cmd;
	eat_token(token);
	pipe->cmd2.cmd = token->content;
	eat_token(token);
	data_parsing->nb_token -= 2;
	node.leaf = pipe;
	return (node);
}
