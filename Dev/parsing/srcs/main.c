/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/17 17:20:59 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	ft_print_lst_token(t_tokens **token)
{
	t_tokens	*tmp;
	int			i;

	i = 0;
	tmp = *token;
	printf("ENTER PRINT LST TOKEN \n");
	if (tmp->content == NULL && tmp->next->content != NULL)
	{
		printf("Le premier maillon est nul\n");
		tmp = (*token)->next;
	}
	while (tmp->next)
	{
		printf("LST CONTENT : %s\n", tmp->content);
		tmp = tmp->next;
		i++;
	}
}

/// heredoc == nouveau fd[0].
int	main(int argc, char **argv)
{
	t_data		data;
	t_tokens	*tokens;
	t_tree		*tree;

	tokens = NULL;
	tree = NULL;
	init_structures(&data, &tokens, &tree, argv);
	if (argc != 2)
		return (0);
	lexing(&data, &tokens);
	// here doc avant parsing meme si erreur 
	// if (error_syntax(token)== 0)
	// 	ERROR_SYNTAX();
	// else
		// parsing(&tokens, &tree);
	// ft_print_lst_token(&tokens);
	free_structures(&data, &tokens);
	return (0);
}
