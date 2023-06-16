/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:25:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/17 00:09:54 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_cmd_tab(t_ast *ast, int i_arg, int i_red)
{
	if (i_arg == 0)
		(*ast).cmd->argument = NULL;
	else
	{
		(ast)->cmd->argument = (char **)malloc(sizeof (char *) * (i_arg + 1));
		if ((ast)->cmd->argument == NULL)
			return (ERROR_MALLOC);
	}
	if (i_red == 0)
	{
		(ast)->cmd->redirections = NULL;
		(ast)->cmd->redirections_type = NULL;
	}
	else
	{
		(ast)->cmd->redirections = malloc(sizeof (char *) * (i_red + 1));
		if ((ast)->cmd->redirections == NULL)
			return (ERROR_MALLOC);
		(ast)->cmd->redirections_type = malloc(sizeof (int) * (i_red + 1));
		if ((ast)->cmd->redirections_type == NULL)
			return (ERROR_MALLOC);
	}
	return (TRUE);
}

int	init_command_node(t_tokens **token, t_ast *ast)
{
	t_tokens		*tmp;
	int				i_arg;
	int				i_red;
	int				flag;

	flag = TRUE;
	i_arg = 0;
	i_red = 0;
	ast->cmd = malloc(sizeof(t_command_node));
	if (!(ast->cmd))
		return (ERROR_MALLOC);
	(*ast).cmd->cmd = ft_strdup((*token)->content);
	eat_token(token);
	tmp = *token;
	while (tmp && (*tmp).type != PIPE)
	{
		if ((*tmp).type == WORD)
			i_arg++;
		else
			i_red++;
		tmp = tmp->next;
	}
	flag = init_cmd_tab(ast, i_arg, i_red);
	return (flag);
}

void	get_arg(t_tokens **token, t_command_node *cmd)
{
	int	i_arg;
	int	i_red;

	i_arg = 0;
	i_red = 0;
	while (*token && (*token)->type != PIPE)
	{
		if ((*token)->type == WORD)
		{
			cmd->argument[i_arg] = ft_strdup((*token)->content);
			i_arg += 1;
		}
		else
		{
			cmd->redirections[i_red] = ft_strdup((*token)->content);
			cmd->redirections_type[i_red] = ((*token)->type);
			i_red++;
		}
		eat_token(token);
	}
	if (cmd->argument != NULL)
		cmd->argument[i_arg] = NULL;
	if (cmd->redirections != NULL)
	{
		cmd->redirections[i_red] = NULL;
		cmd->redirections_type[i_red] = 0;
	}
}

int	parse_command(t_ast **ast, t_tokens **token)
{
	t_ast	*tmp;
	int		flag;

	printf("Enter in parse command\n");
	tmp = malloc(sizeof(t_ast));
	tmp->type = COMMAND_NODE;
	tmp->cmd = NULL;
	tmp->next = NULL;
	tmp->cmd = malloc(sizeof(t_command_node));
	if (!tmp->cmd)
		return (ERROR_MALLOC);
	flag = init_command_node(token, tmp);
	if (flag != TRUE)
		return (flag);
	get_arg(token, tmp->cmd);
	// print_cmd_node(tmp->cmd);
	// if ((*token))
	// {
	// 	printf("%s\n", (*token)->content);
	// 	printf("%i\n", (*token)->type);
	// }
	ft_lstadd_back_ast_node(ast, tmp);
	return (TRUE);
}
