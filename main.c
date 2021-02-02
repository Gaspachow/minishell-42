/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/02/02 12:45:34 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	end_of_file(t_data *data, char *user_input)
{
	free_env(data->env);
	free(user_input);
	ft_putstr_fd("exit\n", 2);
	exit(EXIT_SUCCESS);
}

int		main(int ac, char **av, char **env)
{
	t_data	data;
	int		gnl;

	ac = 0;
	av = NULL;
	data.env = dup_env(env);
	data.fd_in = 0;
	data.fd_out = 1;
	g_status = 0;
	g_user_input = NULL;
	if (!data.env)
		exit(EXIT_FAILURE);
	while (1)
	{
		sig_init();
		ft_putstr_fd("minishell> ", 2);
		gnl = get_next_line(0, &g_user_input);
		if (!*g_user_input)
			end_of_file(&data, g_user_input);
		else
			parser_start(g_user_input, &data);
		g_user_input = NULL;
	}
	return (0);
}
