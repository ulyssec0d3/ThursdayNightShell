/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brouillon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:16:43 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/21 15:29:03 by lduheron         ###   ########.fr       */
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

// t_tokens	*lexing_word_v1(t_data_lexing *data_lexing, int type)
// {
// 	int	flag_d_quote;
// 	int	flag_s_quote;
// 	int	i;
// 	int	size;

// 	flag_d_quote = 0;
// 	flag_s_quote = 0;
// 	i = data_lexing->pos;
// 	size = 0;
// 	while (data_lexing->line[i] && is_metacharacter(data_lexing->line[i]) == 0)
// 	{
// 		flag_d_quote += is_double_quote(data_lexing->line[i]);
// 		flag_s_quote += is_single_quote(data_lexing->line[i]);
// 		i++;
// 		size++;
// 	}
// 	if ((flag_d_quote % 2) != 0 || (flag_s_quote % 2) != 0)
// 	{
// 		printf("minishell: error syntax (quote open)"); 
// 		// flag == // RETURN
// 	}
// 	return (new_token(data_lexing, type, size));
// }
