/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:33:18 by tpons             #+#    #+#             */
/*   Updated: 2021/02/01 19:22:32 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error_sentence(char *str, int status)
{
	g_status = status;
	ft_putstr_fd(str, 2);
}

int		is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	handle_exit(char **inputs, t_data *data)
{
	g_status = 0;
	if (inputs[1] && is_number(inputs[1]))
	{
		g_status = ft_atoi(inputs[1]);
		if (g_status > 126)
			g_status = 126;
		else if (g_status < 0)
			g_status = 0;
	}
	else if (inputs[1])
		error_sentence("\t\tminishell: numeric argument is required\n", 2);
	free_env(inputs);
	free_env(data->env);
	exit(g_status);
}
