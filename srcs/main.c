/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 18:21:39 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_tokens	*token;
	t_cmd_lst	*cmd_lst;

	if (argc != 2)
		return (0);
	token = NULL;
	cmd_lst = NULL;
	lexing(&token, argv);
	// if (token)
	// 	ft_print_lst_token(token);
	check_syntax(&token);
	parsing(&cmd_lst, &token);
	print_cmd_lst(&cmd_lst);
	(void)env;
	// get_env(env);
	// expand(&cmd_lst, env);
	// free_cmd_lst(&cmd_lst);
	// free(cmd_lst);
	return (0);
}
// dollarentre simple quote = pas de subst saud si simple quote dans double quote.