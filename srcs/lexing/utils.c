/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:34:44 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/18 23:57:58 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// GET_CONTENT : This function copies "size" characters from src
// to dst from the position "start".

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

// IS_METACHARACTER : This function returns 1, if the character sent
// is a metacharacter : |&;<>\()`\n\tspace
// A metacharacter causes termination of a word unless it is quoted.

int	is_metacharacter(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == 38 || c == 59 || c == 60 || c == 62
		|| c == 92 || c == 96 || is_parenthesis(c) == 1 || is_pipe(c) == 1)
		return (1);
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
		type = N_DEF;
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
