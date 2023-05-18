/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:08:03 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/18 15:04:52 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
REMINDER 

	N_DEF 0
	WORD 1
	O_PARENTHESIS 2
	C_PARENTHESIS 3
	PIPE_SIGN 4
	SINGLE_QUOTE 5
	DOUBLE_QUOTE 6
	AND_SIGN 7
	OR_SIGN 8

*/

// NEW TOKEN : Create a new token when then input 
// is not a word, a quote, or a parenthesis. 

t_tokens	*new_token(t_data *data, int type)
{
	char	*content;
	int		i;
	int		size;

	printf("ENTER NEW TOKEN\n");
	i = data->pos;
	content = NULL;
	size = 1;
	while (is_space(data->line[i]) == 0 && data->line[i])
	{
		i++;
		size++;
	}
	content = malloc(sizeof(char *) * (size + 1));
	get_content(content, data->line, size, data->pos);
	return (add_new_token(content, type));
}

// NEW TOKEN WORD : Create a new token when the type of the input is WORD.

t_tokens	*new_token_word(t_data *data)
{
	char	*content;
	int		i;
	int		size;

	printf("ENTER NEW TOKEN CMD\n");
	i = data->pos;
	content = NULL;
	size = 1;
	while (ft_isalpha(data->line[i]) == 1 && data->line[i])
	{
		i++;
		size++;
	}
	content = malloc(sizeof(char *) * (size + 1));
	get_content(content, data->line, size, data->pos);
	return (add_new_token(content, 1));
}

// NEW TOKEN PARENTHESIS (enum 2)

t_tokens	*new_token_parenthesis(t_data *data)
{
	char	*content;
	int		i;
	int		size;

	printf("ENTER NEW TOKEN PARENTHESIS\n");
	i = data->pos;
	content = NULL;
	size = parenthesis_management(data);
	content = malloc(sizeof(char *) * (size + 1));
	get_content(content, data->line, size, data->pos);
	printf("content in parenthesis : %s\n", content);
	return (add_new_token(content, 2));
}

// NEW TOKEN SINGLE QUOTE (enum 5)

t_tokens	*new_token_single_quote(t_data *data)
{
	char	*content;
	int		i;
	int		size;

	printf("ENTER NEW TOKEN SINGLE QUOTE\n");
	i = data->pos;
	content = NULL;
	size = single_quote_management(data);
	content = malloc(sizeof(char *) * (size + 1));
	get_content(content, data->line, size, data->pos);
	printf("content in single quote : %s\n", content);
	return (add_new_token(content, 5));
}

// NEW TOKEN DOUBLE QUOTE (enum 6)

t_tokens	*new_token_double_quote(t_data *data)
{
	char	*content;
	int		i;
	int		size;

	printf("ENTER NEW TOKEN DOUBLE QUOTE\n");
	i = data->pos;
	content = NULL;
	size = double_quote_management(data);
	content = malloc(sizeof(char *) * (size + 1));
	get_content(content, data->line, size, data->pos);
	printf("content in double quote : %s\n", content);
	return (add_new_token(content, 6));
}
