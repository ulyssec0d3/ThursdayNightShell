/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/01 10:00:56 by lduheron         ###   ########.fr       */
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
	}
}

/// heredoc == nouveau fd[0].
int	main(int argc, char **argv)
{
	t_tokens	*tokens;
	t_tree		*tree;

	tokens = NULL;
	tree = NULL;
	if (argc != 2)
		return (0);
	lexing(&tokens, argv);
	// here doc avant parsing meme si erreur ?
	// if (error_syntax(token)== 0)
	// 	ERROR_SYNTAX();
	// else
	ft_print_lst_token(tokens);
	build_tree(&tokens, &tree);
	free_structures(&tokens);
	return (0);
}
