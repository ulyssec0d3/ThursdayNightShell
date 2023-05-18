/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:44:28 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/18 15:22:25 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	j = -1;
	i = -1;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (join != NULL)
	{
		while (s1[++i] != '\0' && s1 != NULL)
			join[i] = s1[++j];
		j = -1;
		while (s2[++j] != '\0')
			join[i++] = s2[j];
		join[i] = '\0';
	}
	free (s1);
	return (join);
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

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}
