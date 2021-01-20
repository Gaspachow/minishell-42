/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:47:05 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/20 13:58:28 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = malloc((len1 + len2 + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_memmove(new, s1, len1);
	ft_memmove(&new[len1], s2, len2);
	new[len1 + len2] = '\0';
	return (new);
}
