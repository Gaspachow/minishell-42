/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:35:31 by tpons             #+#    #+#             */
/*   Updated: 2021/01/15 16:51:49 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**export_env(char **old_env, char *export)
{
	int		i;
	char	**new_env;

	i = 0;
	new_env = malloc(sizeof(char *) * (envlen(old_env) + 1));
	if (!new_env)
		return (0);
	while (old_env[i])
	{
		new_env[i] = ft_strdup(old_env[i]);
		i++;
	}
	free_env(old_env);
	new_env[i] = ft_strdup(export);
	i++;
	new_env[i] = NULL;
	return (new_env);
}

int		handle_export(char **inputs, t_data *data)
{
	int	i;

	i = 1;
	if (inputs[i])
	{
		while (inputs[i])
		{
			data->env = export_env(data->env, inputs[i]);
			if (!data->env)
				exit(EXIT_FAILURE);
			i++;
		}
	}
	else
		ft_putstr("export seul");
	return (1);
}
