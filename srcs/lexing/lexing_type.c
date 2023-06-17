/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:34:38 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/17 19:48:54 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// LEXING_*.c : Find the adequate size of the content and returns the token.

t_tokens	*lexing_double_quote(t_data_lexing *data_lexing)
{
	int		size;

	size = double_quote_management(data_lexing);
	return (new_token(data_lexing, DOUBLE_QUOTE, size));
}

t_tokens	*lexing_redirection(t_data_lexing *data_lexing, int type,
	int size_redirection)
{
	int	i;
	int	size;

	data_lexing->pos += size_redirection;
	if (is_space(data_lexing->line[data_lexing->pos]) == 1)
		data_lexing->pos += 1;
	i = data_lexing->pos;
	size = 0;
	while (data_lexing->line[i] && is_space(data_lexing->line[i]) == 0)
	{
		i++;
		size++;
	}
	return (new_token(data_lexing, type, size));
}

t_tokens	*lexing_single_quote(t_data_lexing *data_lexing)
{
	int		size;

	size = single_quote_management(data_lexing);
	return (new_token(data_lexing, SINGLE_QUOTE, size));
}

t_tokens	*lexing_word(t_data_lexing *data_lexing)
{
	int	i;
	int	size;

	i = data_lexing->pos;
	size = 0;
	while (data_lexing->line[i] && is_space(data_lexing->line[i]) == 0)
	{
		i++;
		size++;
	}
	return (new_token(data_lexing, WORD, size));
}

int	search_substitute_variable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((is_dollar(str[i]) == 1) && str[i + 1])
			if (str[i - 1] && is_single_quote(str[i - 1])
				&& str[i + 1] && is_single_quote(str[i + 1]))
				return (1);
		i++;
	}
	return (0);
}