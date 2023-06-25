/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:07:07 by ulevallo          #+#    #+#             */
/*   Updated: 2023/06/25 07:07:19 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// env with no options or arguments
char	*built_in_env(char **env)
{
	size_t	i;

	i = 0;
	while (env && env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
