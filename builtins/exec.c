/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:01:07 by tpons             #+#    #+#             */
/*   Updated: 2021/01/30 12:38:02 by gsmets           ###   ########.fr       */
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

int		execute_2(char **inputs, t_data *data)
{
	int			i;
	char		**paths;
	int			index;
	struct stat	statounet;

	i = 0;
	statounet.st_mode = 0;
	index = var_index("PATH=", data);
	paths = gen_paths(index, data, inputs[0]);
	while (paths[i])
	{
		stat(paths[i], &statounet);
		if (statounet.st_mode & S_IXUSR)
		{
			if (execve(paths[i], inputs, data->env) != -1)
				return (1);
			return (0);
		}
		i++;
	}
	//need to free paths
	return (0);
}

int		execute(char **inputs, t_data *data)
{
	int			index;
	struct stat	statounet;

	statounet.st_mode = 0;
	index = var_index("PATH=", data);
	stat(inputs[0], &statounet);
	if ((statounet.st_mode & S_IXUSR) &&
	(execve(inputs[0], &inputs[0], data->env) != -1))
			return (1);
	else if (index >= 0)
	{
		if (execute_2(inputs, data))
			return (1);
	}
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
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);
	else
	{
		sig_exec_init();
		if (waitpid(pid, &status, 0) != pid)
			status = -1;
	}
	return (pid);
}
