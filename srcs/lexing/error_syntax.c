/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:08:36 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/20 22:27:02 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// int	check_content_redirection(t_tokens *tmp)
// {
// 	int	i;

// 	i = 0;
// 	if (tmp->type == SIMPLE_IN || tmp->type == SIMPLE_OUT
// 		|| tmp->type == DOUBLE_IN || tmp->type == DOUBLE_OUT)
// 		if (is_word(tmp->content[i]) == 1)
// 			return (0);
// 	return (1);
// }

void	check_syntax(t_tokens **token)
{
	t_tokens	*tmp;

	tmp = *token;
	if (tmp->type == PIPE)
		error_syntax(token);
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->next->type == PIPE)
				if (!(tmp->next->next) || tmp->type == PIPE
					|| tmp->next->next->type == PIPE)
					error_syntax(token);
		}
		else
			if (tmp->type == PIPE)
				error_syntax(token);
		tmp = tmp->next;
		// if (check_content_redirection(tmp) == 0)
		// 	error_redirection(token, tmp);
	}
}

// void	check_consistency(t_tokens **token)
// {
// }

/*
	if (type == PIPE)
	
-- rien apres les operateurs.
-- quote pas fermees.
*/

// int	forbidden_character(char *str)
// {
// 	int		i;
// 	char	*forbidden;

// 	i = 0;
// 	forbidden = "&()";
// 	if ()
// }

int	check_line(t_data_lexing *data_lexing, char *str)
{
	int	i;
	int	flag_in_d_quote;
	int	flag_in_s_quote;

	i = 0;
	flag_in_d_quote = OUT;
	flag_in_s_quote = OUT;
	while (str[i])
	{
		if (is_single_quote(str[i]) == 1)
		{
			flag_in_s_quote = IN;
			while (str[i] && is_single_quote(str[i]) == 0)
				i++;
			if (is_single_quote(str[i]) == 1)
			{
				flag_in_s_quote = OUT;
				i++;
			}
		}
		if (is_double_quote(str[i]) == 1)
		{
			flag_in_d_quote = IN;
			while (str[i] && is_double_quote(str[i]) == 0)
				i++;
			if (is_double_quote(str[i]) == 1)
			{
				flag_in_d_quote = OUT;
				i++;
			}
		}
		i++;
	}
	if (flag_in_d_quote == IN || flag_in_s_quote == IN)
	{
		printf("problem quote\n");
		error_in_lexing(data_lexing, ERROR_SYNTAX);
	}
	return (1);
}
