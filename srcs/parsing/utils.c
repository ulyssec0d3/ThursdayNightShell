/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:31:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/06/01 09:54:29 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// EAT_TOKEN : This function free the token after we worked on it
// and set the pointer to the next token

void	eat_token(t_tokens **tokens)
{
	t_tokens	*tmp;

	tmp = NULL;
	tmp = *tokens;
	if (!tmp)
		return ;
	if (tokens)
		*tokens = (*tokens)->next;
	free(tmp);
}

// void	ft_remove_first_node(t_stack **stack)
// {
// 	t_stack	*head;

// 	head = NULL;
// 	head = *stack;
// 	if (stack)
// 		*stack = (*stack)->next;
// 	free(head);
// }

// // IS_LEAF : This function returns 1 if the token being parse is a leaf.
// int	is_leaf(t_tokens **token)
// {
// 	if (!token->next)
// 		return (1);
// 	return (0);
// }
