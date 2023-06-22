/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:08:36 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/22 14:22:52 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// CHECK REDIRECTION CONTENT : This function searches for syntax error related
// to redirections such as redirections not related to any file or "<>", ">>>",
// "<< <<" and ">|".

void	check_redirection_content(t_tokens **token)
{
	t_tokens	*tmp;

	tmp = *token;
	while (tmp)
	{
		if (tmp->type == SIMPLE_IN || tmp->type == SIMPLE_OUT
			|| tmp->type == DOUBLE_IN || tmp->type == DOUBLE_OUT)
		{
			if (tmp->content == NULL)
				error_syntax(token);
		}
		tmp = tmp->next;
	}
}

// CHECK SYNTAX : This function searches for syntax error related
// to the pipe command such as "|", "||", "cat |" and "| cat". It
// also checks syntax error related to redirection calling
// check_redirection_content funtion.

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
	}
	check_redirection_content(token);
}

// CHECK OPEN S QUOTE : This function ensures that the single quotes in the
// given line are correctly closed.

int	check_open_s_quote(t_data_lexing *data_lexing, char *str, int i)
{
	i++;
	while (str[i] && is_single_quote(str[i]) == 0)
		i++;
	if (str[i] == '\0')
		error_in_lexing(data_lexing, ERROR_SYNTAX);
	if (is_single_quote(str[i]) == 1)
				i++;
	return (i);
}

// CHECK OPEN D QUOTE : This function ensures that the double quotes in the
// given line are correctly closed.

int	check_open_d_quote(t_data_lexing *data_lexing, char *str, int i)
{
	i++;
	while (str[i] && is_double_quote(str[i]) == 0)
		i++;
	if (str[i] == '\0')
		error_in_lexing(data_lexing, ERROR_SYNTAX);
	if (is_double_quote(str[i]) == 1)
		i++;
	return (i);
}

// CHECK LINE : This function ensures that all quotes in the given
// line are correctly closed.

void	check_line(t_data_lexing *data_lexing, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_single_quote(str[i]) == 1)
			i = check_open_s_quote(data_lexing, str, i);
		else if (is_double_quote(str[i]) == 1)
			i = check_open_d_quote(data_lexing, str, i);
		else
			i++;
	}
}
