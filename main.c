/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/01/28 15:19:16 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		gnl;
	char	*user_input;

	ac = 0;
	av = NULL;
	data.env = dup_env(env);
	data.fd_in = 0;
	data.fd_out = 1;
	g_status = 0;
	if (!data.env)
		exit(EXIT_FAILURE);
	while (1)
	{
		sig_init();
		ft_putstr_fd("minishell> ", 2);
		gnl = get_next_line(0, &user_input);
		if (gnl == -1)
			exit(EXIT_FAILURE);
		else if (gnl == 0)
		{
			free_env(data.env);
			free(user_input);
			exit(EXIT_SUCCESS);
		}
		else if (gnl > 0)
			parser_start(user_input, &data);
	}
	return (0);
}
