/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:35:31 by tpons             #+#    #+#             */
/*   Updated: 2021/01/15 17:35:47 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		var_exists(char *name, t_data *data)
{
	int		y;
	int		x;

	x = 0;
	while (data->env[x])
	{
		y = 0;
		while (data->env[x][y] && data->env[x][y] == name[y]
		&& data->env[x][y] != '=' && name[y] != '=')
			y++;
		if (data->env[x][y] == '=' && name[y] == '=')
			return (x);
		x++;
	}
	return (0);
}

void	replace_var(char *new_var, t_data *data, int index)
{
	free(data->env[index]);
	data->env[index] = ft_strdup(new_var);
}

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
	int	index;

	i = 1;
	if (inputs[i])
	{
		while (inputs[i])
		{
			index = var_exists(inputs[i], data);
			if (index > 0)
				replace_var(inputs[i], data, index);
			else
			{
				data->env = export_env(data->env, inputs[i]);
				if (!data->env)
					exit(EXIT_FAILURE);
			}
			i++;
		}
	}
	else
		ft_putstr("export seul");
	return (1);
}
