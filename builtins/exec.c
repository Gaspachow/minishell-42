/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:01:07 by tpons             #+#    #+#             */
/*   Updated: 2021/01/13 12:18:37 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	handle_exec(char **args, char **env)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		if (!execve(args[0], &args[0], env))
			exit(EXIT_FAILURE);
	}
	else if (pid == -1)
		exit(EXIT_FAILURE);
		//status = -1; //ERROR
	else
	{
		if (waitpid(pid, &status, 0) != pid)
			status = -1;
	}
	return (pid);
}
