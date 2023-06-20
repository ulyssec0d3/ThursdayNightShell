/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:55:08 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/20 14:30:34 by lduheron         ###   ########.fr       */
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

// char	*extract_value_draft(char *str)
// {
// 	int		i;
// 	int		len;
// 	int		start;
// 	char	*value;

// 	i = 0;
// 	len = 0;
// 	while (str[i] && str[i] != 36)
// 		i++;
// 	start = i;
// 	if (is_single_quote(str[i]) == 1)
// 	{
// 		while (str[i++] && is_single_quote(str[i]) == 0)
// 			len++;
// 	}
// 	else if (is_parenthesis(str[i]) == 1)
// 		len = is_in_parenthesis(str, start);
// 	value = (char *)malloc(sizeof(char) * (len + 1));
// 	get_content(value, str, start, len);
// 	return (value);
// }


char	*extract_value(char **content, int size)
{
	int	i;
	int	value;

	i = 0;
}

void	substitute_value(t_command_node *cmd_node, int i)
{
	char	*variable;
	char	*substitute;

	variable = extract_value(cmd_node->argument[i], cmd_node->argument_subst[i]);
	substitute = get_env(variable);
	search_and_replace(tree, variable, substitute);
}

int	substitute_arg(t_command_node *cmd_node)
{
	int	i;

	i = 0;
	while (cmd_node->argument_subst && cmd_node->argument_subst[i])
	{
		if (cmd_node->argument_subst[i] != 0)
			substitute_value(cmd->node, i);
		i++;
	}
}

int	expand(t_ast **ast)
{
	t_ast	*tmp;

	tmp = *ast;
	while (tmp)
	{
		if (tmp->type == COMMAND_NODE)
			substitute_arg(tmp->cmd_node);
		tmp = tmp->next;
	}
}

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