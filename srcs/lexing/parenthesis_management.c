/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis_management.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:02:49 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/12 17:10:35 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ASCII CODE FOR PARENTHESIS : 
// ( == 40
// ) == 41

int	is_parenthesis(char c)
{
	return (c == 40 || c == 41);
}

// CPT PARENTHESIS : This function returns 1 if the character is an opening
// parenthesis, -1 for closing parenthesis and 0 if it isn't a parenthesis.

int	cpt_parenthesis(char c)
{
	if (c == 40)
		return (1);
	else if (c == 41)
		return (-1);
	return (0);
}

// Is_in_parenthesis : Starting from an opening parenthesis, 
// searches for the corresponding closing parenthesis and returns 
// the size of the buffer to parse.

int	is_in_parenthesis(char *str, int start)
{
	int	pos_tmp;
	int	cpt;
	int	size;

	cpt = 1;
	pos_tmp = start + 1;
	size = 1;
	while (str[pos_tmp] && cpt != 0)
	{
		cpt += cpt_parenthesis(str[pos_tmp]);
		size++;
		pos_tmp++;
	}
	return (size + 1);
}
