/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:05:09 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/18 16:54:26 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if (*str != c && *(str - 1) == c)
			i++;
	}
	return (i);
}

static char		*newsplit(char const *str, char c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (!(ptr = malloc((i + 1) * sizeof(char))))
		return (NULL);
	ft_memmove(ptr, str, i);
	ptr[i] = '\0';
	return (ptr);
}

char			**ft_split(char const *str, char c)
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
		while (*str == c)
			str++;
		if (!(tab[i++] = newsplit(str, c)))
			return (NULL);
		while (*str != c && *str)
			str++;
	}
	tab[i] = NULL;
	return (tab);
}
