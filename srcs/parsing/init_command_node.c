/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_command_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:32:36 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/20 14:33:02 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_command_node_to_null(t_command_node *cmd_node)
{
	cmd_node->argument = NULL;
	cmd_node->argument_subst = NULL;
	cmd_node->redirections = NULL;
	cmd_node->redirections_type = NULL;
	cmd_node->redir_subst = NULL;
}

int	init_arg_tab(t_ast *ast, int i_arg)
{
	if (i_arg != 0)
	{
		ast->cmd_node->argument = malloc(sizeof (char *) * (i_arg + 1));
		if (ast->cmd_node->argument == NULL)
			return (ERROR_MALLOC);
		ast->cmd_node->argument_subst = malloc(sizeof (int) * (i_arg + 1));
		if (ast->cmd_node->argument_subst == NULL)
			return (ERROR_MALLOC);
	}
	return (SUCCESS);
}

int	init_redir_tab(t_ast *ast, int i_redir)
{
	if (i_redir != 0)
	{
		ast->cmd_node->redirections = malloc(sizeof (char *) * (i_redir + 1));
		if (ast->cmd_node->redirections == NULL)
			return (ERROR_MALLOC);
		ast->cmd_node->redirections_type = malloc(sizeof (int) * (i_redir + 1));
		if (ast->cmd_node->redirections_type == NULL)
			return (ERROR_MALLOC);
		ast->cmd_node->redir_subst = malloc(sizeof (char *) * (i_redir + 1));
		if (ast->cmd_node->redir_subst == NULL)
			return (ERROR_MALLOC);
	}
	return (SUCCESS);
}

int	init_command_node(t_tokens **token, t_ast *ast)
{
	t_tokens		*tmp;
	int				i_arg;
	int				i_redir;
	int				flag;

	flag = SUCCESS;
	i_arg = 0;
	i_redir = 0;
	ast->cmd_node = malloc(sizeof(t_command_node));
	if (!(ast->cmd_node))
		return (ERROR_MALLOC);
	set_command_node_to_null(ast->cmd_node);
	tmp = *token;
	while (tmp && (*tmp).type != PIPE)
	{
		if ((*tmp).type == WORD)
			i_arg++;
		else
			i_redir++;
		tmp = tmp->next;
	}
	flag = init_arg_tab(ast, i_arg);
	flag = init_redir_tab(ast, i_redir);
	return (flag);
}