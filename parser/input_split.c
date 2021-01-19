/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:50:50 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/19 16:29:59 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

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

	quote = 0;
	len = get_newsplit_len(src);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	copy_newsplit(src, dst, quote);
	return (dst);
}

char			**input_split(char *str)
{
	char	**inputs;
	size_t	count;
	size_t	i;

	count = stringcount(str);
	inputs = malloc((count + 1) * sizeof(char *));
	if (!inputs)
		return (NULL);
	i = 0;
	while (i < count)
	{
		inputs[i++] = newsplit(str);
		if (!inputs)
			return (NULL);
		str = find_next_input(str);
	}
	inputs[i] = NULL;
	return (inputs);
}
