/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:48:49 by tpons             #+#    #+#             */
/*   Updated: 2021/02/04 18:58:36 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Function handle_pwd :
*/

void	handle_pwd(t_data *data)
{
	ft_putstr(data->pwd);
	ft_putstr("\n");
	g_status = 0;
}
