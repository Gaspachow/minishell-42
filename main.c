/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/01/16 12:32:54 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*user_input;

	ac = 0;
	av = NULL;
	data.status = 0;
	data.env = dup_env(env);
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
