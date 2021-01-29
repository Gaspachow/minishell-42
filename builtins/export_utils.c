/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:35:31 by tpons             #+#    #+#             */
/*   Updated: 2021/01/29 16:47:43 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		print_export(char **env)
{
	int	i;
	int j;
	int	equal;

	i = 0;
	while (env[i])
	{
		equal = 1;
		j = 0;
		ft_putstr("declare -x ");
		while (env[i][j])
		{
			if (env[i][j] == '\\' || env[i][j] == '$' ||
			env[i][j] == '\'' || env[i][j] == '\"')
				write(1, "\\", 1);
			write(1, &env[i][j], 1);
			if (env[i][j] == '=' && equal)
			{
				write(1, "\"", 1);
				equal++;
			}
			j++;
		}
		write(1, "\"", 1);
		write(1, "\n", 1);
		i++;
	}
	return (1);
}

// char	*dup_env_loop(char *env)
// {
// 	char	*data_env;
// 	int		j;
// 	int		k;
// 	int		equal;
	
// 	j = 0;
// 	k = 0;
// 	equal = 1;
// 	data_env = malloc(sizeof(char) * (ft_strlen(env) + 3));
// 	if (!data_env)
// 		exit(EXIT_FAILURE);
// 	while (env[j])
// 	{
// 		data_env[k] = env[j];
// 		if (env[j] == '=' && equal)
// 		{
// 			data_env[++k] = '\"';
// 			equal = 0;
// 		}
// 		k++;
// 		j++;
// 	}
// 	data_env[k] = '\"';
// 	data_env[++k] = '\0';
// 	return (data_env);
// }

// char	**copy_export_env(char **env)
// {
// 	char	**data_env;
// 	int		i;

// 	i = 0;
// 	data_env = malloc(sizeof(char *) * envlen(env));
// 	if (!data_env)
// 		exit(EXIT_FAILURE);
// 	while (env[i])
// 	{
// 		data_env[i] = dup_env_loop(env[i]);
// 		i++;
// 	}
// 	data_env[i] = 0;
// 	return (data_env);
// }
