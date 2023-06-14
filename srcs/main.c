/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/14 14:38:22 by lduheron         ###   ########.fr       */
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

// void	print_ast(t_root **tree)
// {
// 	int	i; // nb nodes

// 	i = 0;
// 	while (ast->next)
// 	{
// 		printf();
// 	}
// }

void	print_cmd_node(t_command_node *cmd)
{
	int	j;

	j = 0;
	while (cmd->argument[j])
	{
		printf("Argument[%i] : %s\n", j, cmd->argument[j]);
		j++;
	}
	j = 0;
	while (cmd->redirections[j])
	{
		printf("Redirection[%i] : %s\n", j, cmd->redirections[j]);
		printf("Redirection_type[%i] : %i\n", j, (cmd->redirections_type[j][0]));
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_tokens	*tokens;
	t_root		*tree;

	tokens = NULL;
	tree = NULL;
	if (argc != 2)
		return (0);
	lexing(&tokens, argv);
	if (tokens)
		ft_print_lst_token(tokens);
	build_tree(&tokens, &tree);
	free_structures(&tokens);
	if (tokens)
		free(tokens);
	return (0);
}
