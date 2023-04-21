/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:17:07 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/21 21:37:23 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

// RECURSIVE PARSING
// LEXER FUNCTION READS THE INPUT AND BREAK IT TO A TOKEN
// https://www.booleanworld.com/building-recursive-descent-parsers-definitive-guide/?utm_content=cmp-true

// if (line[i] == '$' && line[i + 1])

// NEW TOKEN : From the position given, create a new token. 
// Return the size of the new token.
// tester le int strch 

int	create_new_token(t_tokens **token, char *line, int i)
{
	int		cpy_i;
	char	*str;

	printf("CREATE NEW TOKEN FUNCTION\n");
	cpy_i = i;
	str = NULL;
	printf("line[i] in create new token : %c\n", line[i]);
	while (line[i])
	{
		printf("Entree boucle while\n");
		if (is_single_quote(line[i]) == 1)
		{
			printf("pos opening single quote : %i\n", i);
			i += int_strchr(line, i, 34);
			printf("pos closing single quote : %i\n", i);
			break ;
		}
		i++;
		(*token)->type = 4;
	}
	// ecrire fonction qui fait une petite copie du content genre mix entre strdup et strlcpy
	// lst_add_back(token, str);
	// return (ft_strlen(token->content));
	return (i);
}

// LEXING FUNCTION : This function parses the line in tokens
// and store them in a linked list.

void	lexing(t_tokens **token, char *line)
{
	int	i;

	i = 0;
	printf("ENTER LEXING FUNCTION\n");
	while (line[i])
	{
		while (is_space(line[i] == 1))
			i++;
		i += create_new_token(token, line, i);
		break ;
	}
}
	// if (is_single_quote(line[i]) == 1)
		// {
		// 	printf("single quote found, pos : %i\n", i);
		// 	i += int_strchr(line, i, 34);
		// 	printf("pos closing single quote : %i\n", i);
		// }

	