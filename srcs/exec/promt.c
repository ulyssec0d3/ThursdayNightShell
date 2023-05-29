/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulevallo <ulevallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:36:30 by ulevallo          #+#    #+#             */
/*   Updated: 2023/05/29 14:55:28 by ulevallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

bool	parse(const char *command)
{
	(void)command;
	return (true);
}

void	exec(const char *command)
{
	printf("the command you ran is: %s\n", command);
}

void	prompt(char **env)
{
	char	*buffer;
	int		err;

	(void)env;
	err = 0;
	while (!err)
	{
		if (buffer)
			free(buffer);
		buffer = readline("hi:");
		if (parse(buffer))
			exec(buffer);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	prompt(env);
}
