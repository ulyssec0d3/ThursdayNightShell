/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:34:38 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/13 17:24:14 by lduheron         ###   ########.fr       */
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
	// if (is_space(data_lexing->pos) == 1)
	// {
	// 	printf("test/n");
	// 	data_lexing->pos += 1;
	// }
	i = data_lexing->pos;
	size = 0;
	while (is_space(data_lexing->line[i]) == 0 && data_lexing->line[i])
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
	while (is_space(data_lexing->line[i]) == 0 && data_lexing->line[i])
	{
		i++;
		size++;
	}
	return (new_token(data_lexing, WORD, size));
}
