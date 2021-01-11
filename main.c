/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/01/11 17:25:48 by gsmets           ###   ########.fr       */
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
		inputs = ft_split(user_input, ' ');
		parser(inputs);

	}
	return (0);
}


int	parser(char **inputs)
{
	if (!*inputs)
		return (0);
	if (!ft_strcmp(inputs[0], "echo"))
		handle_echo(inputs);
	else
		write(1, "try again\n", 10);
	return (0);
}