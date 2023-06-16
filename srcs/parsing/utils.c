/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:31:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/15 23:37:23 by lduheron         ###   ########.fr       */
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
	if (cmd->argument != NULL)
	{
		while (cmd->argument[i])
		{
			free(cmd->argument[i]);
			i++;
		}
		free(cmd->argument);
	}
	i = 0;
	if (cmd->redirections != NULL)
	{
		while (cmd->redirections[i])
		{
			free(cmd->redirections[i]);
			i++;
		}
		free(cmd->redirections);
		free(cmd->redirections_type);
	}
}

void	free_ast(t_ast **ast)
{
	t_ast	*tmp;

	while (*ast)
	{
		tmp = (*ast)->next;
		if ((*ast)->type == COMMAND_NODE)
		{
			free_command_node((*ast)->cmd);
			free((*ast)->cmd);
		}
		free(*ast);
		*ast = tmp;
	}
}
