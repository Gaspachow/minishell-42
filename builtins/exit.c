/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:33:18 by tpons             #+#    #+#             */
/*   Updated: 2021/01/28 17:33:32 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_exit(char **inputs, t_data *data)
{
	free_env(inputs);
	free_env(data->env);
	exit(EXIT_SUCCESS);
}
