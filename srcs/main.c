/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/15 22:43:35 by lduheron         ###   ########.fr       */
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

void	print_ast(t_ast *ast)
{
	t_ast	tmp;

	tmp = *ast;
	while (ast->next)
	{
		printf("type : %i", tmp.type);
		if (tmp.type == COMMAND_NODE)
			print_cmd_node(tmp.cmd);
		ast = ast->next;
	}
}

// void	print_cmd_node_m(t_command_node *cmd)
// {
// 	int	i;

// 	printf("Enter in print cmd node\n");
// 	i = 0;
// 	if (cmd->argument != NULL)
// 	{
// 		while (cmd->argument[i])
// 		{
// 			printf("Argument[%i] : %s\n", i, cmd->argument[i]);
// 			i++;
// 		}
// 	}
// 	i = 0;
// 	if (cmd->redirections != NULL)
// 	{
// 		while (cmd->redirections[i])
// 		{
// 			printf("Redirection[%i] : %s\n", i, cmd->redirections[i]);
// 			printf("Redirection_type[%i] : %i\n", i, *(cmd->redirections_type[i]));
// 			i++;
// 		}
// 	}
// }

void print_cmd_node(t_command_node *cmd)
{
    int i;

    printf("Enter in print cmd node\n");
    i = 0;
    if (cmd->argument != NULL)
    {
        while (cmd->argument[i])
        {
            printf("Argument[%i] : %s\n", i, cmd->argument[i]);
            i++;
        }
    }
    i = 0;
    if (cmd->redirections != NULL)
    {
        while (cmd->redirections[i])
        {
            printf("Redirection[%i] : %s\n", i, cmd->redirections[i]);
            printf("Redirection_type[%i] : %i\n", i, (cmd->redirections_type[i]));
            i++;
        }
    }
}


int	main(int argc, char **argv)
{
	t_tokens	*token;
	t_ast		*ast;

	token = NULL;
	ast = malloc(sizeof(t_ast));
	if (!ast)
		return (ERROR_MALLOC);
	ast = NULL;
	if (argc != 2)
		return (0);
	lexing(&token, argv);
	// if (token)
	// 	ft_print_lst_token(token);
	build_tree(&ast, &token);
	// print_ast(ast);
	// free_structures(&tokens);
	// if (tokens)
	// 	free(tokens);
	return (0);
}
