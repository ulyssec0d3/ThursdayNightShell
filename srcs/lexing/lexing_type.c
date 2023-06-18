/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:34:38 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/19 00:07:23 by lduheron         ###   ########.fr       */
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
	data_lexing->pos += size_redirection;
	if (is_space(data_lexing->line[data_lexing->pos]) == 1)
		data_lexing->pos += 1;
	return (lexing_word(data_lexing, type));
}

t_tokens	*lexing_single_quote(t_data_lexing *data_lexing)
{
	int		size;

	size = single_quote_management(data_lexing);
	return (new_token(data_lexing, SINGLE_QUOTE, size));
}

t_tokens	*lexing_word(t_data_lexing *data_lexing, int type)
{
	int	flag_d_quote;
	int	flag_s_quote;
	int	i;
	int	size;

	flag_d_quote = 0;
	flag_s_quote = 0;
	i = data_lexing->pos;
	size = 0;
	while (data_lexing->line[i] && is_metacharacter(data_lexing->line[i]) == 0)
	{
		flag_d_quote += is_double_quote(data_lexing->line[i]);
		flag_s_quote += is_single_quote(data_lexing->line[i]);
		i++;
		size++;
	}
	if ((flag_d_quote % 2) != 0 || (flag_s_quote % 2) != 0)
	{
		printf("minishell: error syntax (quote open)");
		// return ;
		// return (NULL);
	}
	return (new_token(data_lexing, type, size));
}

// int	search_substitute_variable(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((is_dollar(str[i]) == 1) && str[i + 1])
// 			if (str[i - 1] && is_single_quote(str[i + 1])
// 				&& str[i + 1] && is_single_quote(str[i + 1]))
// 				return (1);
// 		i++;
// 	}
// 	return (0);
// }
