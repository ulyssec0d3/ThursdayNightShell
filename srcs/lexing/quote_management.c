/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:58:52 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/18 15:04:52 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// SINGLE_QUOTE_MANAGEMENT : Starting from an opening single quote, 
// searches for the closing single quote and return 
// the size of the buffer to parse.

int	single_quote_management(t_data *data)
{
	int	pos_tmp;
	int	size;

	pos_tmp = data->pos + 1;
	size = 1;
	while (data->line[pos_tmp] && is_single_quote(data->line[pos_tmp]) == 0)
	{
		size++;
		pos_tmp++;
	}
	return (size + 1);
}

// DOUBLE_QUOTE_MANAGEMENT : Starting from an opening double quote, 
// searches for the closing single quote and return 
// the size of the buffer to parse.

int	double_quote_management(t_data *data)
{
	int	pos_tmp;
	int	size;

	pos_tmp = data->pos + 1;
	size = 1;
	while (data->line[pos_tmp] && is_double_quote(data->line[pos_tmp]) == 0)
	{
		size++;
		pos_tmp++;
	}
	return (size + 1);
}
