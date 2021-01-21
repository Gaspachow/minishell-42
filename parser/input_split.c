/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:50:50 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/21 19:26:06 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		*find_next_input(char *str)
{
	char	quote;
	int		slash_count;

	str--;
	while (*(++str))
	{
		if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			while (*str != quote)
			{
				slash_count = 0;
				while (*str == '\\' && quote == '"' && ++slash_count)
					str++;
				if (slash_count && !(slash_count % 2))
					str--;
				str++;
			}
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
	int		slash_count;

	i = 1;
	str--;
	while (*(++str))
	{
		if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			while (*str != quote)
			{
				slash_count = 0;
				while (*str == '\\' && quote == '"' && ++slash_count)
					str++;
				if (slash_count && !(slash_count % 2))
					str--;
				str++;
			}
		}
		if (*str == ' ')
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
	len = ft_strlen(src);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	copy_newsplit(src, dst, quote);
	return (dst);
}

char			*newsplit_export(char *src)
{
	int		len;
	char	*dst;

	len = ft_strlen(src);
	dst = malloc((len * 2) * sizeof(char));
	if (!dst)
		return (NULL);
	copy_newsplit_export(src, dst);
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
		if (i > 0 && !ft_strcmp(inputs[0], "export"))
			inputs[i++] = newsplit_export(str);
		else
			inputs[i++] = newsplit(str);
		if (i > 0 && !inputs[i - 1])
			return (NULL);
		str = find_next_input(str);
	}
	inputs[i] = NULL;
	return (inputs);
}
