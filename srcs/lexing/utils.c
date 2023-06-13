/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:34:44 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/13 17:18:37 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_content(char *dst, char *src, unsigned int size, unsigned int start)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = start;
	if (size > 0)
	{
		while (src[i] && j < size)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	return (0);
}

// IS_REDIRECTION : This functions returns 0 if the given string 
// contains a redirection, else, it returns the corresponding 
// enum_type_token code.

int	is_redirection(t_data_lexing *data_lexing)
{
	char	*string;
	int		type;

	string = malloc(sizeof(char) * 3);
	string[0] = (*data_lexing).line[(*data_lexing).pos];
	string[1] = (*data_lexing).line[(*data_lexing).pos + 1];
	string[2] = '\0';
	if (ft_strncmp(string, "<<", 2) == 0)
		type = DOUBLE_IN;
	else if (ft_strncmp(string, ">>", 2) == 0)
		type = DOUBLE_OUT;
	else if (ft_strncmp(string, "<", 1) == 0)
		type = SIMPLE_IN;
	else if (ft_strncmp(string, ">", 1) == 0)
		type = SIMPLE_OUT;
	else
		type = 0;
	free (string);
	return (type);
}

int	int_strchr(const char *s, int start, int c)
{
	const unsigned char	cpy_c = (unsigned char)c;
	int					i;

	i = (int)start;
	while (s[i] != cpy_c && s[i] != '\0')
		++i;
	if (s[i] == cpy_c)
	{
		printf("pos closing single quote : %i\n", i);
		return (i - start);
	}
	return (0);
}
