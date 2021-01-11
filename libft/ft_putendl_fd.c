/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:35:31 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/09 18:45:19 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *str, int fd)
{
	int count;

	if (str == NULL)
		return ;
	count = 0;
	while (str[count])
		count++;
	write(fd, str, count);
	write(fd, "\n", 1);
}
