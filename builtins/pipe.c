/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:50:16 by tpons             #+#    #+#             */
/*   Updated: 2021/01/14 15:45:58 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
**	coucou
*/

int		handle_pipe(char *input1, char *input2, char **env)
{
	int		oldfd;
	pid_t	pid;
	int		fds[2];
	int		status;

	if (pipe(fds) < 0)
		exit(EXIT_FAILURE);// return (0);
	pid = fork();
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], 1);
		parser_delegator(input1, env, 1, fds);
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);//return (0);
	else
	{
		close(fds[1]);
		if (waitpid(pid, &status, 0) != pid)
			exit(EXIT_FAILURE);//return (0);
		oldfd = dup(0);
		dup2(fds[0], 0);
		parser_start(input2, env);
		close(fds[0]);
		dup2(oldfd, 0);
	}
	return (1);
}
