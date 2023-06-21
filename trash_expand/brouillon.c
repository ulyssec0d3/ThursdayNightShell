/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brouillon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:16:43 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 14:53:42 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	search_substitute_variable(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((is_dollar(str[i]) == 1) && str[i + 1])
// 			if (str[i - 1] && is_single_quote(str[i + 1])
// 				&& str[i + 1] && is_single_quote(str[i + 1]))
// 				return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	search_substitute_variable(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if ((is_dollar(str[i]) == 1) && str[i + 1])
// 			if (str[i - 1] && is_single_quote(str[i - 1])
// 				&& str[i + 1] && is_single_quote(str[i + 1]))
// 				return (1);
// 		i++;
// 	}
// 	return (0);
// }

// Is_operator : this function checks if the first character of a
// string is valid.

// int	is_operator(char c)
// {
// 	if (ft_strncmp(c, ">", 1) == 0)
// 		return (1);
// 	if (ft_strncmp(c, "<", 1) == 0)
// 		return (1);
// 	if (ft_strncmp(c, "|", 1) == 0)
// 		return (1);
// 	return (0);
// }