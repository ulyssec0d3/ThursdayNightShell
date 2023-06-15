/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operator_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:07:06 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/15 12:10:46 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast	parse_pipe(t_tokens **token)
{
	t_ast	ast_node;

	ast_node.type = PIPE_NODE;
	ast_node.cmd = NULL;
	ast_node.next = NULL;
	eat_token(token);
	return (ast_node);
}
