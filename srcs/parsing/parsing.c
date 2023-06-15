/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/15 12:39:34 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	build_tree(t_ast *ast, t_tokens **token)
{
	int i = 0;
	printf("Enter in build tree\n");
	while (i < 1)
	{
		if ((*token)->next->type != PIPE)
			*ast = parse_command(token);
		else
			*ast = parse_pipe(token);
		ast = (*ast).next;
		i++;
	}
}

/////// PROTEGER TOUS LES MALLOCS !!!! ///////// 
