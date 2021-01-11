/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:10:08 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/08 15:28:34 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int count;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	count = 0;
	while (str[count])
		count++;
	write(1, str, count);
}
