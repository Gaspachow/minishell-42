/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:48:49 by tpons             #+#    #+#             */
/*   Updated: 2021/01/30 12:52:02 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Function handle_pwd :
*/

int	handle_pwd(t_data *data)
{
	int		index;
	char	*buf;

	index = var_index("PWD", data);
	if (index == -1)
		return (0);
	buf = data->env[index];
	ft_putstr(strchr(buf, '=') + 1);
	ft_putstr("\n");
	return (0);
}
