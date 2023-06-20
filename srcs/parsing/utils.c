/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:31:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/20 14:36:27 by lduheron         ###   ########.fr       */
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

void	free_arg_in_node(t_command_node *cmd_node)
{
	int	i;

	i = 0;
	while (cmd_node->argument[i])
	{
		free(cmd_node->argument[i]);
		i++;
	}
	free(cmd_node->argument_subst);
	free(cmd_node->argument);
}

void	free_redir_in_node(t_command_node *cmd_node)
{
	int	i;

	i = 0;
	while (cmd_node->redirections[i])
	{
		free(cmd_node->redirections[i]);
		i++;
	}
	free(cmd_node->redirections);
	free(cmd_node->redirections_type);
	free(cmd_node->redir_subst);
}

void	free_command_node(t_command_node *cmd_node)
{
	if (cmd_node->argument != NULL)
		free_arg_in_node(cmd_node);
	if (cmd_node->redirections != NULL)
		free_redir_in_node(cmd_node);
}

void	free_ast(t_ast **ast)
{
	t_ast	*tmp;
	int		i;

	i = 0;
	while (*ast)
	{
		if ((*ast)->next)
			tmp = (*ast)->next;
		else
			break ;
		if ((*ast)->type == COMMAND_NODE)
		{
			free_command_node((*ast)->cmd_node);
			free((*ast)->cmd_node);
		}
		free(*ast);
		i += 1;
		*ast = tmp;
	}
	if ((*ast)->type == COMMAND_NODE)
	{
		i += 1;
		free_command_node((*ast)->cmd_node);
		free((*ast)->cmd_node);
	}
}
