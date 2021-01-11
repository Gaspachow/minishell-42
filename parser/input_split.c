/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:50:50 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/11 18:05:30 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int		isEmptyString(const char *str)
{
	if (*str != '"' && *str != '\'')
		return (0);
	else if (*str == *(str + 1))
		return (1);
	return (0);
}

static void		add_string(char *ptr, char const*src, size_t i)
{
	while (i)
	{
		if (isEmptyString(src))
		{
				src++;
				i--;
		}
		else
		{
			*ptr = *src;
			ptr++;
		}
		src++;
		i--;
	}
	*ptr = '\0';
}

static size_t	stringcount(char const *str, char c)
{
	int i;

	i = 1;
	while (*str == c && *str)
		str++;
	if (!(*str))
		return (0);
	while (*(++str))
	{
		if (*str == '"' && *(str - 1) == c)
		{
			str = ft_strchr(str + 1,'"');
			i++;
		}
		else if (*str == '\'' && *(str - 1) == c)
		{
			str = ft_strchr(str + 1, '\'');
			i++;
		}
		else if (*str != c && *(str - 1) == c)
			i++;
	}
	return (i);
}

static char		*newsplit(char const *str, char c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (*str == '"')
		while (str[++i] && str[i] != '"')
			;
	else if (*str == '\'')
		while (str[++i] && str[i] != '\'')
			;
	else
	{
		while (str[i] != c && str[i])
		{
			i++;
		}
	}
	if (*str == '"' || *str == '\'')
	{
		str++;
		i--;
	}
	if (!(ptr = malloc((i + 1) * sizeof(char))))
		return (NULL);
		ft_putnbr(i);
	add_string(ptr, str, i);
	return (ptr);
}

char			**input_split(char const *str, char c)
{
	char	**tab;
	size_t	count;
	size_t	i;

	if (str == NULL)
		return (NULL);
	count = stringcount(str, c);
	if (!(tab = malloc((count + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		while(isEmptyString(str))
			str = str + 2;
		while (*str == c)
			str++;
		if (!(tab[i++] = newsplit(str, c)))
			return (NULL);
			ft_putchar('-');
			ft_putstr(tab[i -1]);
			ft_putchar('\n');
		if (*str == '"')
			str = ft_strchr(str + 1,'"') + 1;
		else if (*str == '\'')
			str = ft_strchr(str + 1, '\'') + 1;
		else
			while (*str != c && *str && *str != '\'' && *str != '"')
				str++;
	}
	tab[i] = NULL;
	return (tab);
}
