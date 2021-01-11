/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:32:06 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/07 11:32:19 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(needle);
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && i + len <= size)
	{
		if (ft_strncmp(haystack, needle, len) == 0)
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
