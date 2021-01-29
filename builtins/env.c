/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:03:40 by tpons             #+#    #+#             */
/*   Updated: 2021/01/29 11:52:55 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env(char **env)
{
	int	i;
	int	env_len;

	i = 0;
	env_len = envlen(env);
	while (i < env_len)
		free(env[i++]);
	free(env);
}

int		envlen(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (++i);
}

char	*dup_env_loop(char *env)
{
	char	*data_env;
	int		j;
	int		k;
	int		equal;
	
	j = 0;
	k = 0;
	equal = 1;
	data_env = malloc(sizeof(char) * (ft_strlen(env) + 3));
	if (!data_env)
		exit(EXIT_FAILURE);
	while (env[j])
	{
		data_env[k] = env[j];
		if (env[j] == '=' && equal)
		{
			data_env[++k] = '\"';
			equal = 0;
		}
		k++;
		j++;
	}
	data_env[k] = '\"';
	data_env[++k] = '\0';
	return (data_env);
}

char	**dup_env(char **env)
{
	char	**data_env;
	int		i;

	i = 0;
	data_env = malloc(sizeof(char *) * envlen(env));
	if (!data_env)
		exit(EXIT_FAILURE);
	while (env[i])
	{
		data_env[i] = dup_env_loop(env[i]);
		i++;
	}
	data_env[i] = 0;
	return (data_env);
}

int		handle_env(char **env)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (env[i])
	{
		str = ft_strstr(env[i], "=");
		if (str)
		{
			j = 0;
			while (env[i][j])
			{
				if (env[i][j + 1] == '\"' && env[i][j + 2] != '\0')
				{
					write(1, &env[i][j], 1);
					j += 2;
				}
				if (env[i][j + 1] == '\0')
					break;
				write(1, &env[i][j], 1);
				j++;
			}
			ft_putchar('\n');
		}
		i++;
	}
	return (1);
}
