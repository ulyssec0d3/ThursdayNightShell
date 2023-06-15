/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:31:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/15 22:26:35 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// EAT_TOKEN : This function free the token after we worked on it
// and set the pointer to the next token

void	eat_token(t_tokens **tokens)
{
	t_tokens	*tmp;

	tmp = NULL;
	tmp = *tokens;
	if (!tmp)
		return ;
	if (tokens)
		*tokens = (*tokens)->next;
	free(tmp);
}

void	free_command_node(t_command_node *cmd)
{
	int	i;

	free(cmd->cmd);
	i = 0;
	while (i < 3)
	{
		free(cmd->argument[i]);
		i++;
	}
	free(cmd->argument);
	i = -1;
	if (cmd->redirections != NULL)
	{
		while (cmd->redirections[i++])
			free(cmd->redirections[i]);
	}
	// i = -1;
	// if (cmd->redirections_type != NULL)
	// {
	// 	while (cmd->redirections_type[i++])
	// 		free(cmd->redirections_type[i]);
	// }
}
