/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:50:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/19 15:40:28 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_data_lexing(t_data_lexing *data_lexing)
{
	free(data_lexing->line);
}

void	error_in_lexing(t_data_lexing *data_lexing, int code)
{
	if (code == ERROR_MALLOC)
		printf("minishell: error malloc");
	else if (code == ERROR_SYNTAX)
		printf("minishell: syntax error near unexpected token ''\n");
	free_data_lexing(data_lexing);
	exit(1);
}

void	error_syntax(t_tokens **tokens)
{
	if (tokens)
		free_token_structure(tokens);
	printf("minishell: syntax error near unexpected token ''\n");
	exit(1);
}
