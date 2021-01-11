/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/01/11 16:20:19 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*user_input;
	char	**input;
	int		i;

	user_input = NULL;
	input= NULL;
	while (1)
	{
		i = 0;
		ft_putstr("minishell> ");
		get_next_line(0, &user_input);
		input = ft_split(user_input, ' ');
		while (input[i])
		{
			ft_putstr(input[i++]);
			ft_putstr("\n");
		}
		ft_putstr("\n");
	}
	return (0);
}
