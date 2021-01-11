/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:21:15 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/17 11:19:07 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getitoalen(long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n /= 10)
		i++;
	return (i);
}

static int		itoa_divpow(long n)
{
	int	div;

	div = 1;
	if (n < 0)
		n = -n;
	while (n /= 10)
		div *= 10;
	return (div);
}

static void		itoa_assign(char *str, size_t len, int div, long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (i < len)
	{
		str[i] = ((n / div) % 10) + '0';
		i++;
		div /= 10;
	}
	str[i] = '\0';
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		div;
	long	ln;

	ln = (long)n;
	len = getitoalen(ln);
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	div = itoa_divpow(ln);
	itoa_assign(str, len, div, ln);
	return (str);
}
