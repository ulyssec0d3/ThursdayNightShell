/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:25:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 23:48:51 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// FILL_ARG :

int	fill_arg(t_cmd_node *cmd_node, char *content, int i)
{
	int	nb_subst;
	int	j;

	j = 0;
	nb_subst = nb_dollar(content);
	cmd_node->argument[i] = ft_strdup(content);
	cmd_node->arg_subst[i] = malloc(sizeof (int) * (nb_subst + 1));
	cmd_node->arg_subst[i][nb_subst] = -2;
	while (j < nb_subst)
	{
		cmd_node->arg_subst[i][j] = -5;
		cmd_node->arg_subst[i][j] = is_substitutable(cmd_node->argument[i],
				j + 1);
		j++;
	}
	return (1);
}

int	fill_redirection_save(t_cmd_node *cmd_node, char *content, int type, int i)
{
	cmd_node->redir[i] = ft_strdup(content);
	cmd_node->redir_type[i] = type;
	cmd_node->redir_sub[i] = 0;
	return (1);
}

int	fill_redirection(t_cmd_node *cmd_node, char *content, int type, int i)
{
	int	nb_subst;
	int	j;

	j = 0;
	nb_subst = nb_dollar(content);
	cmd_node->redir[i] = ft_strdup(content);
	cmd_node->redir_type[i] = type;
	cmd_node->redir_sub[i] = malloc(sizeof (int) * (nb_subst + 1));
	cmd_node->redir_sub[i][nb_subst] = -2;
	while (j < nb_subst)
	{
		cmd_node->redir_sub[i][j] = -5;
		cmd_node->redir_sub[i][j] = is_substitutable(cmd_node->redir[i], j + 1);
		j++;
	}
	return (1);
}

void	set_last_c_null(t_cmd_node *cmd_node, int i_arg, int i_redir)
{
	if (cmd_node->argument != NULL)
	{
		cmd_node->argument[i_arg] = NULL;
		cmd_node->arg_subst[i_arg] = 0;
	}
	if (cmd_node->redir != NULL)
	{
		cmd_node->redir[i_redir] = NULL;
		cmd_node->redir_type[i_redir] = 0;
		cmd_node->redir_sub[i_redir] = 0;
	}
}

void	get_arg(t_tokens **token, t_cmd_node *cmd_node)
{
	int	i_arg;
	int	i_redir;

	i_arg = 0;
	i_redir = 0;
	while (*token && (*token)->type != PIPE)
	{
		if ((*token)->type == WORD)
			i_arg += fill_arg(cmd_node, (*token)->content, i_arg);
		else
			i_redir += fill_redirection(cmd_node, (*token)->content,
					(*token)->type, i_redir);
		eat_token(token);
	}
	set_last_c_null(cmd_node, i_arg, i_redir);
}
