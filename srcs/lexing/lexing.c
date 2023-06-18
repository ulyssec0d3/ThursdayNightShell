/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:17:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/19 00:06:17 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ADD NEW TOKEN : Creates a new token (Like a ft_lstnew but with type).

t_tokens	*add_new_token(char *content, int type)
{
	t_tokens	*new_elem;

	new_elem = malloc (sizeof(t_tokens));
	if (new_elem == NULL)
		return (NULL);
	new_elem->type = type;
	new_elem->len = ft_strlen(content);
	new_elem->content = ft_strdup(content);
	new_elem->next = NULL;
	return (new_elem);
}

// NEW TOKEN : Create a new token when then input 
// is not a word, a quote, or a parenthesis.

t_tokens	*new_token(t_data_lexing *data_lexing, int type, int size)
{
	char	*content;

	content = NULL;
	content = malloc(sizeof(char *) * (size + 1));
	if (!content)
		return (NULL);
	get_content(content, data_lexing->line, size, data_lexing->pos);
	return (add_new_token(content, type));
}

// FIND TYPE : Returns the type of the input.

int	find_type(t_data_lexing **data_lexing)
{
	int	type;

	type = N_DEF;
	if ((*data_lexing)->line[(*data_lexing)->pos] == 124)
		type = PIPE;
	else if (is_single_quote((*data_lexing)->line[(*data_lexing)->pos]) == 1)
		type = SINGLE_QUOTE;
	else if (is_double_quote((*data_lexing)->line[(*data_lexing)->pos]) == 1)
		type = DOUBLE_QUOTE;
	else if (is_redirection(*data_lexing) != N_DEF)
		type = is_redirection(*data_lexing);
	else if (is_metacharacter((*data_lexing)->line[(*data_lexing)->pos]) == 0)
		type = WORD;
	return (type);
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
		return (new_token(data_lexing, PIPE, 1));
	return (0);
}

// LEXING FUNCTION : This function parses the line in tokens
// and store them in a linked list.
void	lexing(t_tokens **token, char **argv)
{
	int				len;
	t_data_lexing	data_lexing;
	t_tokens		*tmp_token;

	len = 0;
	init_data_lexing_structure(&data_lexing, argv);
	while (data_lexing.pos < data_lexing.len)
	{
		len = 0;
		while (is_space(data_lexing.line[data_lexing.pos]) == 1)
			data_lexing.pos++;
		tmp_token = which_new_token(&data_lexing);
		// if (tmp_token == NULL)
			// return (NULL);
		len = ft_strlen(tmp_token->content);
		ft_lstadd_back(token, tmp_token);
		data_lexing.pos += len;
	}
	free(data_lexing.line);
}
