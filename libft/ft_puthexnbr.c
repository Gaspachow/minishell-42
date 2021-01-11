/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:51:12 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/15 14:14:37 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	gethexnbrlen(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n /= 16)
		i++;
	return (i);
}

void			ft_puthexnbr(unsigned int n, int allcaps)
{
	size_t		len;
	int			div;
	char		c;
	char		*hexbase;

	hexbase = "0123456789abcdef";
	if (allcaps)
		hexbase = "0123456789ABCDEF";
	div = 1;
	len = gethexnbrlen(n);
	while (--len)
		div *= 16;
	while (div)
	{
		c = hexbase[((n / div) % 16)];
		write(1, &c, 1);
		div /= 16;
	}
}
