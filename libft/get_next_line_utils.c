/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:56:41 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/30 14:00:28 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (!(*(str + 1)))
			return (i + 1);
		if (!(*(str + 2)))
			return (i + 2);
		if (!(*(str + 3)))
			return (i + 3);
		if (!(*(str + 4)))
			return (i + 4);
		i += 5;
		str += 5;
	}
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	if (ptr1 < ptr2)
		while (n--)
			*(ptr1++) = *(ptr2++);
	else
		while (n--)
			*(ptr1 + n) = *(ptr2 + n);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(new = malloc((len1 + len2 + 1) * sizeof(char))))
	{
		free((char *)s1);
		free((char *)s2);
		return (NULL);
	}
	ft_memmove(new, s1, len1);
	ft_memmove(&new[len1], s2, len2);
	new[len1 + len2] = '\0';
	return (new);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (src[len] && src[len] != '\n')
		len++;
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *str, unsigned int index, size_t len)
{
	char	*new;
	size_t	j;

	if (!str)
		return (NULL);
	if (index >= ft_strlen(str))
		len = 0;
	if (!(new = malloc((len + 1) * sizeof(char))))
	{
		free((char *)str);
		return (NULL);
	}
	j = 0;
	while (len-- && str[index])
	{
		new[j] = str[index];
		j++;
		index++;
	}
	new[j] = '\0';
	return (new);
}
