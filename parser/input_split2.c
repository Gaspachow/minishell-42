/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:01:44 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/21 20:40:21 by gsmets           ###   ########.fr       */
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

void	add_escaped_char(char *src, char *dst, int *i, int *j)
{
	dst[(*j)++] = '\\';
	dst[(*j)++] = src[(*i)++];
}

void	copy_double(char *src, char *dst, int *i, int *j)
{
	(*i)++;
	while (src[(*i)] != '"')
	{
		if (src[(*i)] == '\\')
		{
			if (src[(*i) + 1] == '\\' || src[(*i) + 1] == '$' ||
				src[(*i) + 1] == '"')
			{
				dst[(*j)++] = src[(*i)++];
				dst[(*j)++] = src[(*i)++];
			}
			else
				add_escaped_char(src, dst, i, j);
		}
		else if (src[(*i)] == '$')
			add_escaped_char(src, dst, i, j);
		else
			dst[(*j)++] = src[(*i)++];
	}
	(*i)++;
}

void	copy_single(char *src, char *dst, int *i, int *j)
{
	(*i)++;
	while (src[(*i)] != '\'')
	{
		if (src[(*i)] == '\\' || src[(*i)] == '$' ||
				src[(*i)] == '"')
			add_escaped_char(src, dst, i, j);
		else
			dst[(*j)++] = src[(*i)++];
	}
	(*i)++;
}

void	copy_newsplit_export(char *src, char *dst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] != ' ' && src[i] != '=' && src[i])
		dst[j++] = src[i++];
	if (src[i] == '=')
	{
		dst[j++] = src[i++];
		dst[j++] = '"';
		while (src[i] != ' ' && src[i])
		{
			if (src[i] == '"')
				copy_double(src, dst, &i, &j);
			else if (src[i] == '\'')
				copy_single(src, dst, &i, &j);
			else
				dst[j++] = src[i++];
		}
		dst[j++] = '"';
		dst[j] = '\0';
	}
	else
		dst[j] = '\0';
}
