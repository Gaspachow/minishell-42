/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:48:49 by tpons             #+#    #+#             */
/*   Updated: 2021/01/12 14:03:15 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0); //getcwd return an allocated string filled with the path if param are a NULL string and size = 0
	ft_putstr(buf);
	free(buf);
	ft_putstr("\n");
	return (0);
}