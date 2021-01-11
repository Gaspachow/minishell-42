/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:51:12 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/15 15:10:10 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	getptrnbrlen(unsigned long long n)
{
	size_t	i;

	i = 1;
	while (n /= 16)
		i++;
	return (i);
}

void			ft_putptrnbr(unsigned long long n)
{
	size_t						len;
	unsigned long long			div;
	char						c;
	char						*ptrbase;

	ptrbase = "0123456789abcdef";
	div = 1;
	len = getptrnbrlen(n);
	while (--len)
		div *= 16;
	while (div)
	{
		c = ptrbase[((n / div) % 16)];
		write(1, &c, 1);
		div /= 16;
	}
}
