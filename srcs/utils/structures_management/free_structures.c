/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:09:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/14 14:35:46 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear(t_tokens **lst)
{
	t_tokens	*tmp;

	while (*lst && lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	free_command_node(t_command_node *cmd)
{
	int	i;

	free(cmd->cmd);
	i = -1;
	while (cmd->argument[i++])
		free(cmd->argument[i]);
	i = -1;
	while (cmd->redirections[i++])
		free(cmd->redirections[i]);
	i = -1;
	while (cmd->redirections_type[i++])
		free(cmd->redirections_type[i]);
}

void	free_structures(t_tokens **tokens)
{
	free_token_structure(tokens);
}

// FREE TOKEN STRUCTURE : Free the elements of a t_tokens structure.

void	free_token_structure(t_tokens **tokens)
{
	t_tokens	*tmp;

	while (*tokens && tokens)
	{
		tmp = (*tokens)->next;
		free((*tokens)->content);
		free(*tokens);
		*tokens = tmp;
	}
}
