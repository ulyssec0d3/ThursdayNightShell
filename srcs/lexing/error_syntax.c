/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:08:36 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/20 11:19:28 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Is_operator : this function checks if the first character of a
// string is valid.

// int	is_operator(char c)
// {
// 	if (ft_strncmp(c, ">", 1) == 0)
// 		return (1);
// 	if (ft_strncmp(c, "<", 1) == 0)
// 		return (1);
// 	if (ft_strncmp(c, "|", 1) == 0)
// 		return (1);
// 	return (0);
// }

// int	check_content_redirection(t_tokens *tmp)
// {
// 	int	i;

// 	i = 0;
// 	if (tmp->type == SIMPLE_IN || tmp->type == SIMPLE_OUT
// 		|| tmp->type == DOUBLE_IN || tmp->type == DOUBLE_OUT)
// 		if (is_word(tmp->content[i]) == 1)
// 			return (0);
// 	return (1);
// }

void	check_syntax(t_tokens **token)
{
	t_tokens	*tmp;

	tmp = *token;
	if (tmp->type == PIPE)
		error_syntax(token);
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->next->type == PIPE)
				if (!(tmp->next->next) || tmp->type == PIPE
					|| tmp->next->next->type == PIPE)
					error_syntax(token);
		}
		else
			if (tmp->type == PIPE)
				error_syntax(token);
		tmp = tmp->next;
		// if (check_content_redirection(tmp) == 0)
		// 	error_redirection(token, tmp);
	}
}

// void	check_consistency(t_tokens **token)
// {
// }

/*
	if (type == PIPE)
	
-- rien apres les operateurs.
-- quote pas fermees.
*/