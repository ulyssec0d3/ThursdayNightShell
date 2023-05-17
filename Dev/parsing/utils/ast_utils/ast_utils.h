/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:12:35 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/17 17:49:09 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_UTILS_H
# define AST_UTILS_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

// Ft_split.c
char	**ft_split(char const *s, char c);

// Is_something.c
int		ft_isalpha(int c);
int		is_space(char c);
int		is_sign(char c);
int		is_pipe(char c);

// Lexing_utils.c
char	*ft_strjoin(char *s1, char *s2);
int		int_strchr(const char *s, int start, int c);
int		get_content(char *dst, char *src, unsigned int size,
			unsigned int start);
char	*ft_strdup(char *src);

// Parsing_utils.c
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// Utils.c
int		ft_strlen(char *str);

#endif
