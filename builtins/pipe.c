/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:50:16 by tpons             #+#    #+#             */
/*   Updated: 2021/01/30 13:05:51 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
**	coucou
*/

int		handle_pipe(char *input1, char *input2, t_data *data)
{
	int		oldfd;
	pid_t	pid;
	int		fds[2];
	int		status;

	if (pipe(fds) < 0)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
	{
		free(input2);
		dup2(fds[1], 1);
		close(fds[0]);
		close(fds[1]);
		handle_basic(input1, data, 1);
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);
	else
	{
		free(input1);
		if (waitpid(pid, &status, 0) != pid)
			exit(EXIT_FAILURE);
		oldfd = dup(0);
		dup2(fds[0], 0);
		close(fds[0]);
		close(fds[1]);
		parser_start(input2, data);
		dup2(oldfd, 0);
	}
	return (1);
}
