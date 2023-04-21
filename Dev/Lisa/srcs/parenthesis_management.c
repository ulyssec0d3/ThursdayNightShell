/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis_management.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:02:49 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/21 19:49:30 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

// ASCII CODE FOR PARENTHESIS : 
// ( == 40
// ) == 41

int	is_parenthesis(char c)
{
	return (c == 40 || c == 41);
}

// CPT PARENTHESIS : This function returns 1 if the character is an opening
//parenthesis, -1 for closing parenthesis and 0 if not a parenthesis.

int	cpt_parenthesis(char c)
{
	if (c == 40)
		return (1);
	else if (c == 41)
		return (-1);
	return (0);
}

// PARENTHESIS MANAGEMENT : absolute unuseful mess at the moment.

void	parenthesis_management(char *token)
{
	int	cpt;
	int	i;

	i = 1;
	cpt = 1;
	while (cpt != 0)
	{
		cpt += cpt_parenthesis(token[i]);
		i++;
	}
}
