/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:04:28 by tpons             #+#    #+#             */
/*   Updated: 2021/01/11 13:37:22 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char *line;

	while (1)
	{
		line = malloc(sizeof(char));
		if (!line)
			return (1);
		ft_putstr("minishell>");
		get_next_line(0, &line);
		ft_putstr(line);
		ft_putstr("\n");
	}
	return (0);
}
