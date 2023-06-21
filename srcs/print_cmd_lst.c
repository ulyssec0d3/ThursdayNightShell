/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:02:00 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 13:29:15 by lduheron         ###   ########.fr       */
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

	i = 1;
	printf("Cmd : %s\n", cmd_node->argument[0]);
	printf("Cmd_subst : %i\n\n", cmd_node->argument_subst[0]);
	if (cmd_node->argument != NULL)
	{
		while (cmd_node->argument[i])
		{
			printf("Argument[%i] : %s\n", i, cmd_node->argument[i]);
			printf("Argument_subst[%i] : %d\n\n", i, cmd_node->argument_subst[i]);
			i++;
		}
	}
	i = 0;
	if (cmd_node->redir != NULL)
	{
		while (cmd_node->redir[i])
		{
			printf("Redirection[%i] : %s\n", i, cmd_node->redir[i]);
			printf("Redirection_type[%i] : %i\n", i,
				(cmd_node->redir_type[i]));
			printf("redir_sub[%i] : %i\n\n", i, cmd_node->redir_sub[i]);
			i++;
		}
	}
}

void	print_cmd_lst(t_cmd_lst **cmd_lst)
{
	t_cmd_lst	*tmp;
	int			i;

	printf("\nPRINT cmd_lst : \n\n");
	tmp = *cmd_lst;
	i = 0;
	while (tmp)
	{
		printf(" ----- NODE %i ----- \n", i);
		printf("type : %i\n", tmp->type);
		if (tmp->type == COMMAND_NODE)
			print_cmd_node(tmp->cmd_node);
		printf("\n\n");
		if (!tmp->next)
			break ;
		i++;
		tmp = tmp->next;
	}
}
