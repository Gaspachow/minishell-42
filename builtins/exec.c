/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:01:07 by tpons             #+#    #+#             */
/*   Updated: 2021/01/14 19:02:43 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_exec(char **args, t_data *data)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		if (!execve(args[0], &args[0], data->env))
			exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);
		//status = -1; //ERROR
	else
	{
		if (waitpid(pid, &status, 0) != pid)
			status = -1;
	}
	return (pid);
}
