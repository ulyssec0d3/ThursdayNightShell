/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:26:04 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/17 18:26:53 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// Parsing.c
void		eat_token(t_tokens **tokens);
void		build_tree(t_tokens **token, t_tree **tree);
void		parse_word(t_tokens **token, t_tree **tree);

#endif
