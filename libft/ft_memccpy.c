/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:05:30 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/07 11:05:32 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;
	unsigned char stop;

	stop = (unsigned char)c;
	if (dest == NULL && src == NULL)
		return (NULL);
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (n-- && *ptr2 != stop)
		*(ptr1++) = *(ptr2++);
	if (*ptr2 == stop)
	{
		*(ptr1++) = stop;
		return (ptr1);
	}
	else
		return (NULL);
}
