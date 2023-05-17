/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:56:55 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/17 16:04:01 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

enum e_type_token
{
	N_DEF,
	WORD,
	O_PARENTHESIS,
	C_PARENTHESIS,
	PIPE_SIGN,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	AND_SIGN,
	OR_SIGN
} ;

typedef struct s_tokens
{
	enum e_type_token	type;
	int					len;
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
