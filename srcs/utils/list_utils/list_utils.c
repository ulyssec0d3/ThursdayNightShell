/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:30:00 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/29 17:26:28 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstsize(t_tokens *lst)
{
	int	size;

	size = 0;
	if (!(lst))
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_tokens	*ft_lstlast(t_tokens *lst)
{
	t_tokens	*tmp;

	tmp = NULL;
	if (!(lst))
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_tokens **lst, t_tokens *new)
{
	t_tokens	*tmp;

	tmp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}


void	ft_lstadd_front(t_tokens **lst, t_tokens *new)
{
	if (lst == NULL)
		*lst = new;
	new->next = *lst;
	*lst = new;
}

t_tokens	*ft_lstnew(char *content)
{
	t_tokens	*new_elem;

	new_elem = malloc (sizeof(t_tokens));
	if (!new_elem)
		return (NULL);
	new_elem->type = 0;
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}
