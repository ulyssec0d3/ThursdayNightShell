/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:37:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/21 18:53:39 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_utils.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	cpy_c = (unsigned char)c;
	size_t				i;

	i = 0;
	while (s[i] != cpy_c && s[i] != '\0')
		++i;
	if (s[i] == cpy_c)
		return ((char *)(s + i));
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
