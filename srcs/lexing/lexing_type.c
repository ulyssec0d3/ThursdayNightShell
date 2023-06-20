/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:34:38 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/20 15:47:53 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// LEXING_*.c : Find the adequate size of the content and returns the token.

// t_tokens	*lexing_double_quote(t_data_lexing *data_lexing)
// {
// 	int		size;

// 	size = double_quote_management(data_lexing);
// 	return (new_token(data_lexing, DOUBLE_QUOTE, size));
// }

t_tokens	*lexing_redirection(t_data_lexing *data_lexing, int type,
	int size_redirection)
{
	data_lexing->pos += size_redirection;
	if (is_space(data_lexing->line[data_lexing->pos]) == 1)
		data_lexing->pos += 1;
	return (lexing_word(data_lexing, type));
}

// t_tokens	*lexing_single_quote(t_data_lexing *data_lexing)
// {
// 	int		size;

// 	size = single_quote_management(data_lexing);
// 	return (new_token(data_lexing, SINGLE_QUOTE, size));
// }

// t_tokens	*lexing_word_v1(t_data_lexing *data_lexing, int type)
// {
// 	int	flag_d_quote;
// 	int	flag_s_quote;
// 	int	i;
// 	int	size;

// 	flag_d_quote = 0;
// 	flag_s_quote = 0;
// 	i = data_lexing->pos;
// 	size = 0;
// 	while (data_lexing->line[i] && is_metacharacter(data_lexing->line[i]) == 0)
// 	{
// 		flag_d_quote += is_double_quote(data_lexing->line[i]);
// 		flag_s_quote += is_single_quote(data_lexing->line[i]);
// 		i++;
// 		size++;
// 	}
// 	if ((flag_d_quote % 2) != 0 || (flag_s_quote % 2) != 0)
// 	{
// 		printf("minishell: error syntax (quote open)"); 
// 		// flag == // RETURN
// 	}
// 	return (new_token(data_lexing, type, size));
// }

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
	// else if (type == SINGLE_QUOTE)
	// 	return (lexing_single_quote(data_lexing));
	// else if (type == DOUBLE_QUOTE)
	// 	return (lexing_double_quote(data_lexing));
	else if (type == PIPE)
		return (new_token_pipe());
	return (0);
}
