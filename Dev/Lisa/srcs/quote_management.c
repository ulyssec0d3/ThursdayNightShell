/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:58:52 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/21 21:07:58 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

// ASCII CODE FOR QUOTES : 
// " == 34
// ' == 39

int	is_double_quote(char c)
{
	return (c == 34);
}

int	is_single_quote(char c)
{
	return (c == 39);
}

int	is_quote(char c)
{
	return (c == 34 || c == 39);
}
