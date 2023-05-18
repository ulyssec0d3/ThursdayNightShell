/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:17:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/18 15:04:52 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// NEW TOKEN : Creates a new token (Like a ft_lstnew but with type).

t_tokens	*add_new_token(char *content, int type)
{
	t_tokens	*new_elem;

	printf("ENTER ADD NEW TOKEN\n");
	new_elem = malloc (sizeof(t_tokens));
	if (!new_elem)
		return (NULL);
	new_elem->type = type;
	new_elem->content = ft_strdup(content);
	new_elem->next = NULL;
	return (new_elem);
}

// FIND TYPE : Returns the type of the input.

int	find_type(t_data **data)
{
	int	type;

	type = N_DEF;
	if (ft_isalpha((*data)->line[(*data)->pos]) == 1)
		type = WORD;
	else if ((*data)->line[(*data)->pos] == 124)
	{
		type = PIPE_SIGN;
		if ((*data)->line[(*data)->pos + 1] == 124)
			type = OR_SIGN;
	}
	else if ((*data)->line[(*data)->pos] == 40)
		type = O_PARENTHESIS;
	else if ((*data)->line[(*data)->pos] == 41)
		type = C_PARENTHESIS;
	else if (is_single_quote((*data)->line[(*data)->pos]) == 1)
		type = SINGLE_QUOTE;
	else if (is_double_quote((*data)->line[(*data)->pos]) == 1)
		type = DOUBLE_QUOTE;
	// else if (ft_strncmp(pos_tmp, "&&", 2) == 0)
	// 	type = AND_SIGN;
	return (type);
}

// WHICH NEW TOKEN : This function creates a token depending on the type
// of the input. The double quote token cannot be implemented for now
// as it would be considered as a new arg and my main only handle argv[1].

t_tokens	*which_new_token(t_data *data)
{
	int			type;

	type = find_type(&data);
	if (type == WORD)
		return (new_token_word(data));
	else if (type == SINGLE_QUOTE)
		return (new_token_single_quote(data));
	// else if (type == DOUBLE_QUOTE)
	// 	return (new_token_double_quote(data));
	else if (type == O_PARENTHESIS)
		return (new_token_parenthesis(data));
	else
		return (new_token(data, type));
	return (0);
}

// LEXING FUNCTION : This function parses the line in tokens
// and store them in a linked list.

void	lexing(t_data *data, t_tokens **token)
{
	int			len;
	t_tokens	*tmp_token;

	len = 0;
	printf("ENTER LEXING FUNCTION\n");
	while (data->pos < data->len)
	{
		len = 0;
		while (is_space(data->line[data->pos] == 1))
			data->pos++;
		tmp_token = which_new_token(data);
		if (tmp_token == NULL)
			return (exit (1));
		len = ft_strlen(tmp_token->content);
		ft_lstadd_back(token, tmp_token);
		data->pos += len;
		free((*tmp_token).content);
	}
}
