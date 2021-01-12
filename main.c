/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/01/12 13:58:54 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*user_input;
	char	**inputs;
	int		i;

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
