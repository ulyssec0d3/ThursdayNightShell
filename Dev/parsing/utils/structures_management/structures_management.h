/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_management.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:16:43 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/17 19:18:12 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_MANAGEMENT_H
# define STRUCTURES_MANAGEMENT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../ast_utils/ast_utils.h"
# include "../list_utils/list_utils.h"
# include "../../srcs/ast.h"

typedef struct s_data {
	char	*line;
	int		pos;
	int		len;
}			t_data;

typedef struct s_tree
{
	char	type;
	char	content;
}	t_tree;

// Init_structures.c 
void		init_data_structure(t_data *data, char **argv);
void		init_token_structure(t_tokens **tokens);
void		init_structures(t_data *data, t_tokens **tokens, t_tree **tree,
				char **argv);
// void		init_tree_structure(t_tree **tree);

// Free_structures.c
void		free_data_structure(t_data *data);
void		free_token_structure(t_tokens **tokens);
void		free_structures(t_data *data, t_tokens **tokens);
// void		free_tree_structure(t_tree **tree);
void		ft_lstclear(t_tokens **lst);

#endif
