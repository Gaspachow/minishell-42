/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/01/23 15:32:18 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*user_input;

	ac = 0;
	av = NULL;
	data.env = dup_env(env);
	data.fd_in = -42;
	data.fd_out = -42;
	if (!data.env)
		exit(EXIT_FAILURE);
	while (1)
	{
		sig_init();
		ft_putstr("minishell> ");
		if (get_next_line(0, &user_input) == 0)
			exit(EXIT_FAILURE);
		parser_start(user_input, &data);
	}
	return (0);
}
