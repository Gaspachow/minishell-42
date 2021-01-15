/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:03:40 by tpons             #+#    #+#             */
/*   Updated: 2021/01/15 16:50:50 by tpons            ###   ########.fr       */
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
	return (++i); //add one for \0 case
}

void	dup_env(t_data *data, char **env)
{
	int	i;

	i = 0;
	data->env = malloc(sizeof(char *) * envlen(env));
	if (!data->env)
		exit(EXIT_FAILURE);
	while (env[i])
	{
		data->env[i]= ft_strdup(env[i]);
		i++;
	}
	data->env[i] = 0;
}

int		handle_env(t_data *data)
{
	int	i;

	i = 0;
	while(data->env[i])
	{
		ft_putstr(data->env[i++]);
		ft_putchar('\n');
	}
	return(1);
}

// int		modify_env(char **inputs, char **env, int modifier)
// {
// 	char **new_env;

// 	if (!check_var(inputs[1]))
// 		exit(EXIT_FAILURE); //temporary (ERROR is : identifiant non-valable)!!
// 	new_env = malloc(sizeof(char *) * (envlen(env) + modifier));
// 	if (!new_env)
// 		exit(EXIT_FAILURE);
// 	if (modifier > 0)
// 		handle_export(inputs[1], env, new_env); //while (inputs[i]) do handle export
// 	else if (modifier < 0)
// 		handle_unset(inputs[1], env, new_env); //while (inputs[i]) do handle unset
// 	//free env ??
// 	return (new_env);
// }
/*
**int		check_var(char **str)
**{
**	int	i;
**
**	i = 0;
**	while (str[i])
**	{
**		if (str[0][0] == '=')
**			return (0);
**		if (!ft_strchr(str[i], '='))
**			return (0);
**		i++;
**	}
**	return (1);
**}
*/
