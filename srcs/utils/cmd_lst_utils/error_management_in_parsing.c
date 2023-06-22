/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:50:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/22 15:34:00 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstclear(t_tokens **lst)
{
	t_tokens	*tmp;

	while (*lst && lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

// FREE TOKEN STRUCTURE : Free the elements of a t_tokens structure.

void	free_token_structure(t_tokens **tokens)
{
	t_tokens	*tmp;

	while (*tokens && tokens)
	{
		tmp = (*tokens)->next;
		free((*tokens)->content);
		free(*tokens);
		*tokens = tmp;
	}
}

void	error_in_lexing(t_data_lexing *data_lexing, int code)
{
	if (code == ERROR_MALLOC)
		printf("minishell: error malloc\n");
	else if (code == ERROR_SYNTAX)
		printf("minishell: syntax error near unexpected token ''\n");
	free(data_lexing->line);
	exit(1);
}

void	error_syntax(t_tokens **tokens)
{
	if (tokens)
		free_token_structure(tokens);
	printf("minishell: syntax error near unexpected token ''\n");
	exit(1);
}
