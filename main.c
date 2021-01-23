/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/01/23 15:23:28 by gsmets           ###   ########.fr       */
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
		ft_putstr("minishell> ");
		get_next_line(0, &user_input);
		parser_start(user_input, &data);
	}
	return (0);
}
