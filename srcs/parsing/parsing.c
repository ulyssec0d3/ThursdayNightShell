/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/13 17:25:48 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	build_tree(t_tokens **token, t_root **tree)
{
	// while ()
	// {
		if ((*token)->next->type != 1)
			parse_command(token, tree);
		// else
		// 	parse_pipe(&data_parsing, token);
	// }
}
