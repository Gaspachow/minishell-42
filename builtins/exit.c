/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:33:18 by tpons             #+#    #+#             */
/*   Updated: 2021/01/28 16:02:49 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_exit(char **inputs, t_data *data)
{
	free_env(inputs);
	free_env(data->env);
	free(inputs);
	free(data->env);
	exit(EXIT_SUCCESS);
}
