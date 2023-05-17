/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:20:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/17 18:22:22 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXING_H
# define LEXING_H

# include "../../utils/structures_management/structures_management.h"
# include "../../utils/ast_utils/ast_utils.h"
# include "../../utils/list_utils/list_utils.h"

# include "../ast.h"

// Lexing.c
t_tokens	*add_new_token(char *content, int type);
int			find_type(t_data **data);
t_tokens	*which_new_token(t_data *data);
void		lexing(t_data *data, t_tokens **token);

// New_token.c
t_tokens	*new_token(t_data *data, int type);
t_tokens	*new_token_word(t_data *data);
t_tokens	*new_token_parenthesis(t_data *data);
t_tokens	*new_token_single_quote(t_data *data);
t_tokens	*new_token_double_quote(t_data *data);

// Parenthesis_management.c
int			cpt_parenthesis(char c);
int			is_parenthesis(char c);
int			parenthesis_management(t_data *data);

// Quote_management.c
int			is_double_quote(char c);
int			is_single_quote(char c);
int			is_quote(char c);
int			single_quote_management(t_data *data);
int			double_quote_management(t_data *data);

#endif
