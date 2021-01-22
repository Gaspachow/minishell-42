/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:48:49 by tpons             #+#    #+#             */
/*   Updated: 2021/01/22 16:40:21 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Function handle_pwd :
** getcwd return an allocated string filled
** with the path if param are a NULL string and size = 0
*/

int	handle_pwd(t_data *data)
{
	char	*buf;

	buf = data->env[var_index("PWD", data)];
	ft_putstr(strchr(buf, '=') + 1);
	ft_putstr("\n");
	return (0);
}
