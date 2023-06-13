/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:34:54 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/13 17:21:38 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data_lexing_structure(t_data_lexing *data_lexing, char **argv)
{
	data_lexing->line = NULL;
	data_lexing->line = ft_strjoin(data_lexing->line, argv[1]);
	data_lexing->len = ft_strlen(data_lexing->line);
	data_lexing->pos = 0;
}
