/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:56:55 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/21 19:45:58 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_tokens {
	int					type;
	char				*content;
	struct s_tokens		*next;
}	t_tokens;

// List_utils.c
void		ft_lstadd_back(t_tokens **lst, t_tokens *new);
void		ft_lstadd_front(t_tokens **lst, t_tokens *new);
int			ft_lstsize(t_tokens *lst);
t_tokens	*ft_lstnew(char *content);
t_tokens	*ft_lstlast(t_tokens *lst);

#endif
