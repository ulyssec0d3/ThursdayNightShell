/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:12:35 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/18 13:14:14 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_alpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	is_dollar(char c)
{
	return (c == 36);
}

int	is_pipe(char c)
{
	return (c == 124);
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v');
}

int	is_number(int c)
{
	return (c >= '0' && c <= '9');
}
