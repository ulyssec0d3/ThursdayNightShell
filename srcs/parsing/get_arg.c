/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:25:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 15:03:55 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// IS_SUBSTITUTABLE : This function returns 0 if it finds a dollar in 
// the string sent. Else, it returns the len of characters to substitute
// behind the $.

int	is_substitutable(char *str)
{
	int	i;
	int	size;

	i = 0;
	while (str[i] && is_dollar(str[i]) == 0)
		i++;
	if (!str[i])
	{
		printf("Nothing to substitute here\n");
		return (0);
	}
	size = 0;
	i++;
	while (is_alpha(str[i]) == 1 || is_number(str[i]) == 1 || str[i] == 95)
	{
		size++;
		i++;
	}
	return (size);
}

// FILL_ARG :

int	fill_arg(t_command_node *cmd_node, char *content, int i)
{
	cmd_node->argument[i] = ft_strdup(content);
	cmd_node->argument_subst[i] = is_substitutable(cmd_node->argument[i]);
	return (1);
}

int	fill_redirection(t_command_node *cmd_node, char *content, int type, int i)
{
	cmd_node->redir[i] = ft_strdup(content);
	cmd_node->redir_type[i] = type;
	cmd_node->redir_sub[i] = is_substitutable(cmd_node->redir[i]);
	return (1);
}

void	set_lcmd_lst_c(t_command_node *cmd_node, int i_arg, int i_redir)
{
	if (cmd_node->argument != NULL)
	{
		cmd_node->argument[i_arg] = NULL;
		cmd_node->argument_subst[i_arg] = 0;
	}
	if (cmd_node->redir != NULL)
	{
		cmd_node->redir[i_redir] = NULL;
		cmd_node->redir_type[i_redir] = 0;
	}
}

void	get_arg(t_tokens **token, t_command_node *cmd_node)
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
	set_lcmd_lst_c(cmd_node, i_arg, i_redir);
}
