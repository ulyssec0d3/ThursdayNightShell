/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:34:54 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/14 16:37:09 by lduheron         ###   ########.fr       */
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

	printf("Enter init command node\n");
	tmp = *token;
	i_arg = 0;
	i_red = 0;
	while (tmp && (*tmp).type != PIPE)
	{
		if ((*tmp).type == WORD)
			i_arg++;
		else
			i_red++;
		tmp = tmp->next;
	}
	// printf("in init command node, i_arg : %i, i_red : %i\n", i_arg, i_red);
	if (i_arg == 0)
		cmd->argument = NULL;
	else
		cmd->argument = (char **)malloc(sizeof (char *) * (i_arg + 1));
	if (cmd->argument == NULL)
		return ;
	if (i_red == 0)
	{
		cmd->redirections = NULL;
		cmd->redirections_type = NULL;
	}
	else
	{
		cmd->redirections = (char **)malloc(sizeof (char *) * (i_red + 1));
		if (cmd->redirections == NULL)
			return ;
		cmd->redirections_type = (int **)malloc(sizeof (int *) * (i_red + 1));
		if (cmd->redirections_type == NULL)
			return ;
	}
}
