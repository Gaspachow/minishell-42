/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:21:58 by tpons             #+#    #+#             */
/*   Updated: 2021/01/13 14:02:13 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_data	init_data(char **env)
{
	t_data	temp;

	temp.user_input = NULL;
	// temp.clean_input = NULL;
	// temp.inputs = NULL;
	temp.env = env;
	return (temp);
}
