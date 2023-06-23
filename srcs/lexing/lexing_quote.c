/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:34:57 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/23 20:33:53 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void quotes_trimming(char *buffer)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (buffer[i])
// 	{
// 		if (is_double_quote(buffer[i]))
// 		{
// 			j = i;
// 			while (buffer[j])
// 			{
// 				buffer[j] = buffer[j + 1];
// 				j++;
// 			}
// 			buffer[j] = 0;
// 			while (buffer[i] && is_double_quote(buffer[i]) == 0)
// 				i++;
// 			j = i;
// 			while (buffer[j])
// 			{
// 				buffer[j] = buffer[j + 1];
// 				j++;
// 			}
// 			buffer[j] = 0;
// 		}
// 		else if (is_single_quote(buffer[i]))
// 		{
// 			j = i;
// 			while (buffer[j])
// 			{
// 				buffer[j] = buffer[j + 1];
// 				j++;
// 			}
// 			buffer[j] = 0;
// 			while (buffer[i] && is_single_quote(buffer[i]) == 0)
// 				i++;
// 			j = i;
// 			while (buffer[j])
// 			{
// 				buffer[j] = buffer[j + 1];
// 				j++;
// 			}
// 			buffer[j] = 0;
// 		}
// 		else
// 			i++;
// 	}
// }

void	quotes_trimming(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i])
	{
		if (is_double_quote(buffer[i]))
		{
			j = i;
			while (buffer[j])
			{
				buffer[j] = buffer[j + 1];
				j++;
			}
			buffer[j] = 0;
			while (buffer[i] && is_double_quote(buffer[i]) == 0)
				i++;
			j = i;
			while (buffer[j])
			{
				buffer[j] = buffer[j + 1];
				j++;
			}
			buffer[j] = 0;
		}
		else if (is_single_quote(buffer[i]))
		{
			j = i;
			while (buffer[j])
			{
				buffer[j] = buffer[j + 1];
				j++;
			}
			buffer[j] = 0;
			while (buffer[i] && is_single_quote(buffer[i]) == 0)
				i++;
			j = i;
			while (buffer[j])
			{
				buffer[j] = buffer[j + 1];
				j++;
			}
			buffer[j] = 0;
		}
		else
			i++;
	}
}

t_tokens	*new_token_double_quote(t_data_lexing *data_lexing, int size)
{
	char	*content_tmp;

	content_tmp = NULL;
	if (size > 0)
	{
		content_tmp = malloc(sizeof(char *) * (size + 1));
		if (content_tmp == NULL)
		{
			free(content_tmp);
			return (NULL);
		}
		get_content(content_tmp, data_lexing->line, size, data_lexing->pos);
	}
	quotes_trimming(content_tmp);
	data_lexing->pos += (size - ft_strlen(content_tmp));
	return (add_new_token(content_tmp, WORD));
}

t_tokens	*new_token_single_quote(t_data_lexing *data_lexing, int size)
{
	char	*content_tmp;

	content_tmp = NULL;
	if (size > 0)
	{
		content_tmp = malloc(sizeof(char *) * (size + 1));
		if (content_tmp == NULL)
		{
			free(content_tmp);
			return (NULL);
		}
		get_content(content_tmp, data_lexing->line, size, data_lexing->pos);
	}
	quotes_trimming(content_tmp);
	data_lexing->pos += (size - ft_strlen(content_tmp));
	return (add_new_token(content_tmp, WORD));
}
