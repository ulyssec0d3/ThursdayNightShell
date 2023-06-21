/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:31:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 23:35:55 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// EAT_TOKEN : This function free the token after we worked on it
// and set the pointer to the next token

void	eat_token(t_tokens **tokens)
{
	t_tokens	*tmp;

	tmp = NULL;
	tmp = *tokens;
	if (!tmp)
		return ;
	if (tokens)
		*tokens = (*tokens)->next;
	free(tmp);
}

int	nb_dollar(char *str)
{
	int	cpt;
	int	i;

	cpt = 0;
	i = 0;
	while (str[i])
	{
		cpt += is_dollar(str[i]);
		i++;
	}
	return (cpt);
}

// IS_SUBSTITUTABLE : This function returns 0 if it finds a dollar in 
// the string sent. Else, it returns the len of characters to substitute
// behind the $. -2 = Nothing to substitute

int	is_substitutable(char *str, int i_dollar)
{
	int	i;
	int	cpt_dollar;
	int	size;

	i = 0;
	cpt_dollar = 0;
	size = 0;
	while (cpt_dollar < i_dollar)
	{
		while (str[i] && is_dollar(str[i]) == 0)
			i++;
		if (!str[i])
			return (-2);
		i++;
		cpt_dollar++;
	}
	while (str[i] && (is_alpha(str[i]) == 1
			|| is_number(str[i]) == 1 || str[i] == 95))
	{
		size++;
		i++;
	}
	return (size);
}
