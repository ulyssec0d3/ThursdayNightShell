
#include "minishell.h"

/// remplacer les return ; par des codes d'erreurs.

void	init_cmd_arg(t_command_node *cmd, int i_arg)
{
	if (i_arg == 0)
		cmd->argument = NULL;
	else
		cmd->argument = (char **)malloc(sizeof (char *) * (i_arg + 1));
	if (cmd->argument == NULL)
		return ;
}

void	init_cmd_redirections(t_command_node *cmd, int i_red)
{
	if (i_red == 0)
	{
		cmd->redirections = NULL;
		cmd->redirections_type = NULL;
	}
	else
	{
		cmd->redirections = (char **)malloc(sizeof (char *) * (i_red + 1));
		if (cmd->redirections == NULL)
			return ;
		cmd->redirections_type = (int **)malloc(sizeof (int *) * (i_red + 1));
		if (cmd->redirections_type == NULL)
			return ;
	}
}

void	init_command_node(t_tokens **token, t_command_node *cmd)
{
	t_tokens		*tmp;
	int				i_arg;
	int				i_red;

	i_arg = 0;
	i_red = 0;
	cmd = malloc(sizeof(t_command_node));
	cmd->cmd = ft_strdup((*token)->content);
	eat_token(token);
	tmp = *token;
	while (tmp && (*tmp).type != PIPE)
	{
		if ((*tmp).type == WORD)
			i_arg++;
		else
			i_red++;
		tmp = tmp->next;
	}
	// printf("in init command node, i_arg : %i, i_red : %i\n", i_arg, i_red);
	init_cmd_arg(cmd, i_arg);
	init_cmd_redirections(cmd, i_red);
}

void	get_arg(t_tokens **token, t_command_node *cmd)
{
	int	i_arg;
	int	i_red;

	i_arg = 0;
	i_red = 0;
	printf("Enter in get arg\n");
	// printf("In get arg, token content : %s, token type : %i\n", (*token)->content, (int)(*token)->type);
	while (token && (*token)->type != PIPE)
	{
		if ((*token)->type == WORD)
		{
			// cmd->argument[i_arg] = malloc(sizeof (char *) * ((*token)->len + 1));
			cmd->argument[i_arg] = ft_strdup((*token)->content);
			i_arg++;
		}
		else
		{
			cmd->redirections[i_red] = ft_strdup((*token)->content);
			cmd->redirections_type[i_red] = (int *)((*token)->type);
			i_red++;
		}
		eat_token(token);
	}
}

void	parse_command(t_tokens **token, t_ast *ast)
{
	printf("Enter in parse command\n");
	ast->type = COMMAND_NODE;
	ast->cmd = NULL;
	ast->next = NULL;
	init_command_node(token, ast->cmd);
	get_arg(token, ast->cmd);
	print_cmd_node(ast->cmd);
	// free_command_node(&cmd);

}

// malloc tous les noeuds