/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:12:35 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/21 21:08:37 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_UTILS_H
# define TOKEN_UTILS_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

// Ft_split.c
char	**ft_split(char const *s, char c);

// Lexing_utils.c
int		int_strchr(const char *s, int start, int c);
int		is_space(char c);
int		is_sign(char c);
int		ft_strlen(char *str);

// Parsing_utils.c
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
