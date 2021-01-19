/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:12:35 by tpons             #+#    #+#             */
/*   Updated: 2021/01/19 15:40:22 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		varname_index(char *name, t_data *data)
{
	int		y;
	int		x;

	x = 0;
	while (data->env[x])
	{
		y = 0;
		while (data->env[x][y] && data->env[x][y] == name[y]
		&& data->env[x][y] != '=' && name[y] != '\0')
			y++;
		if (data->env[x][y] == '=' && name[y] == '\0')
			return (x);
		x++;
	}
	return (0);
}

char	**unset_env(char **old_env, int index)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	new_env = malloc(sizeof(char *) * (envlen(old_env) - 1));
	if (!new_env)
		exit(EXIT_FAILURE);
	while (old_env[i])
	{
		if (i != index)
		{
			new_env[j] = ft_strdup(old_env[i]);
			j++;
		}
		i++;
	}
	free_env(old_env);
	i--;
	new_env[i] = NULL;
	return (new_env);
}

void	handle_unset(char **inputs, t_data *data)
{
	int	i;
	int	index;

	i = 1;
	while (inputs[i])
	{
		index = varname_index(inputs[i], data);
		if (index > 0)
			data->env = unset_env(data->env, index);
		i++;
	}
}
