/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:41:24 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/19 15:43:03 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_number(int c)
{
	return (c >= '0' && c <= '9');
}

// IS_METACHARACTER : This function returns 1, if the character sent
// is a metacharacter : |&;<>\()`\n\tspace
// A metacharacter causes termination of a word unless it is quoted.

int	is_metacharacter(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == 38 || c == 59 || c == 60 || c == 62
		|| c == 92 || c == 96 || is_parenthesis(c) == 1 || is_pipe(c) == 1)
		return (1);
	return (0);
}
