/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:58:21 by ulevallo          #+#    #+#             */
/*   Updated: 2023/06/25 07:07:22 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd(void)
{
	size_t	size;
	char	*path_buffer;

	size = 128;
	while (!path_buffer)
	{
		path_buffer = malloc(sizeof(char) * size);
		if (!path_buffer)
			return (NULL);
		getcwd(path_buffer, size);
		if (!path_buffer)
		{
			free(path_buffer);
			size *= 2;
		}
	}
	return (path_buffer);
}

// pwd with no options
void	built_in_pwd(void)
{
	char	*path_buffer;

	path_buffer = get_pwd();
	if (!path_buffer)
		return ;
	printf("%s\n", path_buffer);
	free(path_buffer);
}
