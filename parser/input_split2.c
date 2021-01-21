/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:01:44 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/21 18:54:25 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_newsplit(char *src, char *dst, char quote)
{
	while (*src != ' ' && *src)
	{
		if (*src == '\'')
		{
			quote = *(src++);
			while (*src != quote)
				*(dst++) = *(src++);
			src++;
		}
		else if (*src == '"')
		{
			quote = *(src++);
			while (*src != quote)
			{
				if (*src == '\\' && (*(src + 1) == quote ||
					*(src + 1) == '\\' || *(src + 1) == '$'))
					src++;
				*(dst++) = *(src++);
			}
			src++;
		}
		else
			*(dst++) = *(src++);
	}
	*dst = '\0';
}


// void	*copy_newsplit_export(char *src, char  *dst, char quote)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while(src[i] != ' ' && src[i] != '=' && src[i])
// 		dst[j++] = src[i++];
// 	if (src[i] == '=')
// 	{
// 		dst[j++] = src[i++];
// 		while (src[i] != ' ' && src[i])
// 		{
// 			if (src[i] == '"')
// 				copy_double(src, dst, &i, &j);
// 			else if (src[i] == '\'')
// 				copy_single(src, dst, &i, &j);
// 			else
// 				dst[j++] = src[i++];
// 		}
// 	}

// }