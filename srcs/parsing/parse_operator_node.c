/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operator_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:07:06 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/16 23:53:30 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_pipe(t_ast **ast, t_tokens **token)
{
	t_ast	*tmp;

	printf("Enter parse pipe\n");
	tmp = malloc(sizeof(t_ast));
	tmp->type = PIPE_NODE;
	tmp->cmd = NULL;
	tmp->next = NULL;
	eat_token(token);
	ft_lstadd_back_ast_node(ast, tmp);
}
