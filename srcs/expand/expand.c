/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:55:08 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/19 14:00:08 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
First, the input is lexed to generate tokens, 
then the tokens are parsed to build the command structure,
and finally, the expand step is performed on the parsed command
to evaluate and substitute variables and command substitutions.

When recreating a shell, implementing the "expand" functionality 
involves identifying variables and command substitutions in the 
input command or expression, evaluating them, and replacing them
with their respective values or output before executing the command.
The AST can help in representing and manipulating the parsed structure
of the command, allowing for efficient expansion and evaluation of variables
and command substitutions.
$(HOME) or $`HOME`.
ATTENTION NESTED EXPANSIONS
*/

// EXPAND, getenv autorisé
// IS_SUBSTITUTABLE : if is  

int	is_substitutable(char *str, int start)
{
	int	i;
	int	size;

	i = start;
	size = 0;
	while (is_alpha(str[i]) == 1 || is_number(str[i]) == 1 || str[i] == 95)
	{
		i++;
		size++;
	}
	return (size);
}

char	*extract_value(char *str)
{
	int		i;
	int		len;
	int		start;
	char	*value;

	i = 0;
	len = 0;
	while (str[i] && str[i] != 36)
		i++;
	start = i;
	if (is_single_quote(str[i]) == 1)
	{
		while (str[i++] && is_single_quote(str[i]) == 0)
			len++;
	}
	else if (is_parenthesis(str[i]) == 1)
		len = is_in_parenthesis(str, start);
	value = (char *)malloc(sizeof(char) * (len + 1));
	get_content(value, str, start, len);
	return (value);
}

void	substitute_value(t_ast *tree)
{
	char	*variable;
	char	*substitute;

	variable = extract_value(tree->value);
	substitute = get_env(variable);
	// search_and_replace(tree, variable, substitute);
}

int	search_substitute_variable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((is_dollar(str[i]) == 1) && str[i + 1])
			if (str[i - 1] && is_single_quote(str[i - 1])
				&& str[i + 1] && is_single_quote(str[i + 1]))
				return (1);
		i++;
	}
	return (0);
}

int	expand(t_ast **ast)
{
	t_ast	*tmp;

	tmp = *ast;
	while (tmp)
	{
		if (is_dollar())
	}
}
// 
// void	expand_2(t_ast **ast)
// {
// 	// t_tree	*tmp;
// 
// 	// tmp = *tree;
// 	// while (tree)
// 	// {
// 	// 	if (search_substitute_variable(tmp->value) == 1)
// 	// 		substitute_value(tmp->value);
// 	// 	tmp = tmp->next;
// 	// }
// 	void(ast);
// 	t_env_lst	*env_lst;
// }
// 
// cas ou le dollar sont dans les singles quotes. 
// si on fait les bonus = expand pendant l'exec.
// echo $PWD != echo $PWD != echo $PWD1