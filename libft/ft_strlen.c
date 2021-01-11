/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:26:09 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/11 16:17:36 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
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
