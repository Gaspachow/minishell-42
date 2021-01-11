/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:41:47 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/16 14:14:59 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*newstr;
	unsigned int	i;

	if (!str || !f)
		return (NULL);
	len = ft_strlen(str);
	if (!(newstr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		newstr[i] = (*f)(i, str[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
