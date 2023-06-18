/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:08:36 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/19 00:01:47 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Is_operator : this function checks if the first character of a string is valid

int	is_operator(char c)
{
	if (ft_strncmp(c, ">", 1) == 0)
		return (1);
	if (ft_strncmp(c, "<", 1) == 0)
		return (1);
	if (ft_strncmp(c, "|", 1) == 0)
		return (1);
	return (0);
}

int	check_content_redirection(t_tokens *tmp)
{
	if (tmp->type == SIMPLE_IN || tmp->type == SIMPLE_OUT
		|| tmp->type == DOUBLE_IN || tmp->type == DOUBLE_OUT)
		if (is_word(tmp->content) == 1)
			return (0);
	return (1);
}

void	check_syntax(t_tokens **tokens)
{
	t_tokens	*tmp;

	tmp = *tokens;
	while (tmp)
	{
		if (token->next->type == PIPE)
			if (token->type == PIPE || token->next->next == PIPE)
				error_syntax(tokens);
		if (check_content_redirection(tmp) == 0)
			error_redirection(tokens, tmp);
	}
}

// void	check_consistency(t_tokens **token)
// {
/*
-- rien apres les operateurs.
-- quote pas fermees.
*/
// }
//