/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:50:50 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/13 12:33:35 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static char		*find_next_input(char *str)
{
	char	quote;

	str--;
	while (*(++str))
	{
		if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			while (*str != quote)
				str++;
		}
		if (*str == ' ')
			return (str + 1);
	}
	return (str);
}

static size_t	stringcount(char *str)
{
	int		i;
	char	quote;

	i = 1;
	if (!(*str))
		return (0);
	str--;
	while (*(++str))
	{
		if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			while (*str != quote)
			{
				str++;
			}
		}
		if (*str == ' ')
			i++;
	}
	return (i);
}

int				get_newsplit_len(char *str)
{
	int		i;
	char	quote;

	i = 0;
	while (*str != ' ' && *str)
	{
		if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			while (*(str++) != quote)
				i++;
		}
		else if (str++)
			i++;
	}
	return (i);
}

char			*newsplit(char *src)
{
	int		len;
	char	*dst;
	char	quote;

	len = get_newsplit_len(src);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (*src != ' ' && *src)
	{
		if (*src == '"' || *src == '\'')
		{
			quote = *(src++);
			while (*src != quote)
			{
				*(dst++) = *(src++);
			}
			src++;
		}
		else
			*(dst++) = *(src++);
	}
	*dst = '\0';
	return (dst - (len));
}

char			**input_split(char *str)
{
	char	**tab;
	size_t	count;
	size_t	i;

	count = stringcount(str);
	tab = malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < count)
	{
		tab[i++] = newsplit(str);
		if (!tab)
			return (NULL);
		str = find_next_input(str);
	}
	tab[i] = NULL;
	return (tab);
}
