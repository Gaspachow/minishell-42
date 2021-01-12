/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/01/12 15:46:36 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*user_input;
	char	**inputs;
	int		i;

	ac = 0;				// temporary
	av = NULL;			// temporary
	env = NULL;			// temporary
	user_input = NULL;
	inputs= NULL;
	while (1)
	{
		i = 0;
		ft_putstr("minishell> ");
		get_next_line(0, &user_input);
		parser(user_input);

	}
	return (0);
}
