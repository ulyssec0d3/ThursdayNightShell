/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt .c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:36:30 by ulevallo          #+#    #+#             */
/*   Updated: 2023/06/21 23:15:17 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(char **env)
{
	t_tokens	*token;
	t_cmd_lst	*cmd_lst;
	char		*buffer;
	int			err;

	(void)env;
	token = NULL;
	cmd_lst = NULL;
	err = 0;
	while (!err)
	{
		if (buffer)
			free(buffer);
		buffer = readline("DavidFinshell: ");
		lexing(&token, buffer);
		check_syntax(&token);
		parsing(&cmd_lst, &token);
		print_cmd_lst(&cmd_lst);
		if (buffer && *buffer)
			add_history(buffer);
	}
}
