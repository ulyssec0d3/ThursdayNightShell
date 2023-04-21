/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:31:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/21 20:42:28 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

//expand : , char **env

int	main(int argc, char **argv)
{
	t_tokens	*tokens;

	tokens = NULL;
	init_token_structure(&tokens);
	if (argc == 2)
		lexing(&tokens, argv[1]);
	free_token_structure(&tokens);
	return (0);
}
