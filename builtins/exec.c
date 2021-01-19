/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:01:07 by tpons             #+#    #+#             */
/*   Updated: 2021/01/19 15:40:03 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
**	CUT "PATH=" if PATH envVAr exists
**	split remaining string at every ':'
**	try executing strjoin(paths[i], inputs[0]) for every path existing
**	if nothing happend return (error)
*/

char	**gen_paths(int index, t_data *data, char *input)
{
	char	*str;
	char	**paths;
	char	*temp;
	int		i;

	i = 0;
	str = ft_strdup(&data->env[index][5]);
	paths = ft_split(str, ':');
	while (paths[i])
	{
		temp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(temp);
		temp = paths[i];
		paths[i] = ft_strjoin(paths[i], input);
		free(temp);
		i++;
	}
	return (paths);
}

int		execute(char **inputs, t_data *data)
{
	int			i;
	int			index;
	char		**paths;
	struct stat	statounet;

	i = 1;
	index = var_index("PATH=", data);
	stat(inputs[0], &statounet);
	if (statounet.st_mode & S_IXUSR)
	{
		execve(inputs[0], &inputs[0], data->env);
		return (1);
	}
	else if (index > 0)
	{
		paths = gen_paths(index, data, inputs[0]);
		while (paths[i])
		{
			stat(paths[i], &statounet);
			if (statounet.st_mode & S_IXUSR)
			{
				execve(paths[i], inputs, data->env);
				return (1);
			}
			i++;
		}
		return (0);
	}
	else
		return (0);
}

int		handle_exec(char **inputs, t_data *data)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		if (!execute(inputs, data))
			exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);
	else
	{
		if (waitpid(pid, &status, 0) != pid)
			status = -1;
	}
	return (pid);
}
