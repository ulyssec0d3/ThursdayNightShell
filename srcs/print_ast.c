/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:02:00 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/19 16:50:12 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_lst_token(t_tokens *token)
{
	t_tokens	*tmp;
	int			i;

	tmp = token;
	i = 0;
	printf("PRINT LST TOKEN\n");
	if (tmp == NULL)
	{
		printf("List is empty.\n");
		return ;
	}
	if (tmp->content == NULL)
	{
		printf("The first node is null.\n");
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		printf("TOKEN NUMBER %i\n", i);
		printf("Content: %s\n", tmp->content);
		printf("Type : %i\n", tmp->type);
		printf("Len : %i\n\n", tmp->len);
		tmp = tmp->next;
		i++;
	}
}

void	print_cmd_node(t_command_node *cmd_node)
{
	int	i;

	i = 0;
	printf("cmd : %s\n", cmd_node->cmd);
	if (cmd_node->argument != NULL)
	{
		while (cmd_node->argument[i])
		{
			printf("Argument[%i] : %s\n", i, cmd_node->argument[i]);
			// printf("Argument_subst[%i] : %s\n", i, cmd_node->argument_subst[i]);
			i++;
		}
	}
	i = 0;
	if (cmd_node->redirections != NULL)
	{
		while (cmd_node->redirections[i])
		{
			printf("Redirection[%i] : %s\n", i, cmd_node->redirections[i]);
			printf("Redirection_type[%i] : %i\n", i,
				(cmd_node->redirections_type[i]));
			// printf("Redirections_subst[%i] : %i\n", i, cmd_node->redirections_subst);
			i++;
		}
	}
}

void	print_ast(t_ast **ast)
{
	t_ast	*tmp;

	printf("\nPRINT AST : \n\n");
	tmp = *ast;
	while (tmp)
	{
		printf("type : %i\n", tmp->type);
		if (tmp->type == COMMAND_NODE)
			print_cmd_node(tmp->cmd_node);
		printf("\n\n");
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}
