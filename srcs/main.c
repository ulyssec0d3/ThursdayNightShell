/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 23:56:43 by lduheron         ###   ########.fr       */
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
		// ft_print_lst_token(token);
		check_syntax(&token);
		parsing(&cmd_lst, &token);
		print_cmd_lst(&cmd_lst);
		if (buffer && *buffer)
			add_history(buffer);
	}
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 1)
		return (0);
	(void)argv;
	prompt(env);
	return (0);
}

// free_cmd_lst(&cmd_lst);
// free(cmd_lst);
// dollar entre simple quote = pas de subst sauf si
//  simple quote dans double quote.