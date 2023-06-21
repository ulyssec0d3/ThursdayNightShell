/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:34:38 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 22:20:49 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// LEXING_*.c : Find the adequate size of the content and returns the token.

t_tokens	*lexing_double_quote(t_data_lexing *data_lexing)
{
	int		size;
	int		i;

	size = double_quote_management(data_lexing->line, data_lexing->pos);
	if (is_space(data_lexing->line[data_lexing->pos + size]) == 1)
		return (new_token(data_lexing, WORD, size));
	else
	{
		i = size + data_lexing->pos;
		while (data_lexing->line[i]
			&& is_metacharacter(data_lexing->line[i]) == 0)
		{
			if (is_double_quote(data_lexing->line[i]) == 1)
				size += double_quote_management(data_lexing->line, i);
			if (is_single_quote(data_lexing->line[i]) == 1)
				size += single_quote_management(data_lexing->line, i);
			i++;
			size++;
		}
	}
	return (new_token(data_lexing, WORD, size));
}

t_tokens	*lexing_single_quote(t_data_lexing *data_lexing)
{
	int		size;
	int		i;

	size = single_quote_management(data_lexing->line, data_lexing->pos);
	if (is_space(data_lexing->line[data_lexing->pos + size]) == 1)
		return (new_token(data_lexing, WORD, size));
	else
	{
		i = size + data_lexing->pos;
		while (data_lexing->line[i] && is_metacharacter(data_lexing->line[i]) == 0)
		{
			if (is_double_quote(data_lexing->line[i]) == 1)
				size += double_quote_management(data_lexing->line, i);
			if (is_single_quote(data_lexing->line[i]) == 1)
				size += single_quote_management(data_lexing->line, i);
			i++;
			size++;
		}
	}
	return (new_token(data_lexing, WORD, size));
}

t_tokens	*lexing_redirection(t_data_lexing *data_lexing, int type,
	int size_redirection)
{
	data_lexing->pos += size_redirection;
	if (is_space(data_lexing->line[data_lexing->pos]) == 1)
		data_lexing->pos += 1;
	return (lexing_word(data_lexing, type));
}

t_tokens	*lexing_word(t_data_lexing *data_lexing, int type)
{
	int	i;
	int	size;

	i = data_lexing->pos;
	size = 0;
	while (data_lexing->line[i] && is_metacharacter(data_lexing->line[i]) == 0)
	{
		if (is_double_quote(data_lexing->line[i]) == 1)
			size += double_quote_management(data_lexing->line, i);
		if (is_single_quote(data_lexing->line[i]) == 1)
			size += single_quote_management(data_lexing->line, i);
		i++;
		size++;
	}
	return (new_token(data_lexing, type, size));
}

// WHICH NEW TOKEN : This function creates a token depending on the type
// of the input. The double quote token cannot be implemented for now
// as it would be considered as a new arg and my main only handle argv[1].
t_tokens	*which_new_token(t_data_lexing *data_lexing)
{
	int			type;

	type = find_type(&data_lexing);
	if (type == WORD)
		return (lexing_word(data_lexing, WORD));
	else if (type == SIMPLE_IN || type == SIMPLE_OUT)
		return (lexing_redirection(data_lexing, type, 1));
	else if (type == DOUBLE_IN || type == DOUBLE_OUT)
		return (lexing_redirection(data_lexing, type, 2));
	else if (type == SINGLE_QUOTE)
		return (lexing_single_quote(data_lexing));
	else if (type == DOUBLE_QUOTE)
		return (lexing_double_quote(data_lexing));
	else if (type == PIPE)
		return (new_token_pipe());
	return (0);
}
