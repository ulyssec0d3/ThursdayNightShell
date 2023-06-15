/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:25:34 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/15 22:26:17 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// remplacer les return ; par des codes d'erreurs.

// void	init_cmd_arg(t_ast **ast, int i_arg)
// {
// 	if (i_arg == 0)
// 		(*ast)->cmd->argument = NULL;
// 	else
// 	(*ast)->cmd->argument = (char **)malloc(sizeof (char *) * (i_arg + 1));
// 	if ((*ast)->cmd->argument == NULL)
// 		return ;
// }

// void	init_cmd_redirections(t_ast **ast, int i_red)
// {
// 	if (i_red == 0)
// 	{
// 		(*ast)->cmd->redirections = NULL;
// 		(*ast)->cmd->redirections_type = NULL;
// 	}
// 	else
// 	{
// 		(*ast)->cmd->redirections = (char **)malloc(sizeof (char *) * (i_red + 1));
// 		if ((*ast)->cmd->redirections == NULL)
// 			return ;
// 		(*ast)->cmd->redirections_type = (int **)malloc(sizeof (int *) * (i_red + 1));
// 		if ((*ast)->cmd->redirections_type == NULL)
// 			return ;
// 	}
// }

void	init_cmd_arg(t_ast *ast, int i_arg)
{
	if (i_arg == 0)
		(*ast).cmd->argument = NULL;
	else
	{
		(ast)->cmd->argument = (char **)malloc(sizeof (char *) * (i_arg + 1));
		if ((ast)->cmd->argument == NULL)
			return ;
	}
}

void	init_cmd_redirections(t_ast *ast, int i_red)
{
	if (i_red == 0)
	{
		(ast)->cmd->redirections = NULL;
		(ast)->cmd->redirections_type = NULL;
	}
	else
	{
		(ast)->cmd->redirections = malloc(sizeof (char *) * (i_red + 1));
		if ((ast)->cmd->redirections == NULL)
			return ;
		(ast)->cmd->redirections_type = malloc(sizeof (int) * (i_red + 1));
		if ((ast)->cmd->redirections_type == NULL)
			return ;
	}
}

	// printf("in init command node, i_arg : %i, i_red : %i\n", i_arg, i_red);
void	init_command_node(t_tokens **token, t_ast *ast)
{
	t_tokens		*tmp;
	int				i_arg;
	int				i_red;

	i_arg = 0;
	i_red = 0;
	ast->cmd = malloc(sizeof(t_command_node));
	printf("%p\n", &ast);
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
	init_cmd_arg(ast, i_arg);
	init_cmd_redirections(ast, i_red);
}

void	get_arg(t_tokens **token, t_command_node *cmd)
{
	int	i_arg;
	int	i_red;

	i_arg = 0;
	i_red = 0;
	printf("Enter in get arg\n");
	// printf("In get arg, token content : %s, token type : %i\n", (*token)->content, (int)(*token)->type);
	while (*token && (*token)->type != PIPE)
	{
		if ((*token)->type == WORD)
		{
			// cmd->argument[i_arg] = malloc(sizeof (char *) * ((*token)->len + 1));
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
	cmd->argument[i_arg] = NULL;
	cmd->redirections[i_red] = NULL;
	cmd->redirections_type[i_red] = 0;	
}

void	parse_command(t_tokens **token, t_ast **ast)
{
	t_ast	*tmp;
	
	(void)ast;
	printf("Enter in parse command\n");
	tmp = malloc(sizeof(t_ast));
	tmp->type = COMMAND_NODE;
	tmp->cmd = NULL;
	tmp->next = NULL;
	tmp->cmd = malloc(sizeof(t_command_node));
	printf("%p\n", &tmp);
	init_command_node(token, tmp);
	get_arg(token, tmp->cmd);
	print_cmd_node(tmp->cmd);
	ft_lstadd_back_ast_node(ast, tmp);
	// print_cmd_node(tmp->cmd);
	// free_command_node(&cmd);
}

// malloc tous les noeuds
// proteger tous les mallocs 