/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:12:35 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/17 18:19:52 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_utils.h"

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_pipe(char c)
{
	return (c == 124);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v');
}

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
