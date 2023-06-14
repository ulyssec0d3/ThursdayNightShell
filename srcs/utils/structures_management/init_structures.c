/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:34:54 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/14 14:31:27 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data_lexing_structure(t_data_lexing *data_lexing, char **argv)
{
	data_lexing->line = NULL;
	data_lexing->line = ft_strjoin(data_lexing->line, argv[1]);
	data_lexing->len = ft_strlen(data_lexing->line);
	data_lexing->pos = 0;
}

void	init_command_node(t_tokens **token, t_command_node *cmd)
{
	t_tokens		*tmp;
	int				i_arg;
	int				i_red;

	tmp = *token;
	i_arg = 0;
	i_red = 0;
	while ((*tmp).type != 1)
	{
		if ((*tmp).type == WORD)
			i_arg++;
		else
			i_red++;
		tmp = tmp->next;
	}
	if (i_arg > 0)
		cmd->argument = (char **)malloc(sizeof (char *) * i_arg);
	if (i_red > 0)
	{
		cmd->redirections = (char **)malloc(sizeof (char *) * i_red); // +1 pour le \n.
		cmd->redirections_type = (int **)malloc(sizeof (int) * i_red); // +1
	}	
}
