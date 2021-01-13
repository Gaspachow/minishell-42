/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/01/13 15:42:37 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*user_input;

	ac = 0;
	av = NULL;
	while (1)
	{
		ft_putstr("minishell> ");
		get_next_line(0, &user_input);
		parser(user_input, env);
	}
	return (0);
}
