/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:44:28 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/21 21:19:25 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_utils.h"

int	int_strchr(const char *s, int start, int c)
{
	const unsigned char	cpy_c = (unsigned char)c;
	size_t				i;

	i = (int)start;
	while (s[i] != cpy_c && s[i] != '\0')
		++i;
	if (s[i] == cpy_c)
		return (i - start);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}
