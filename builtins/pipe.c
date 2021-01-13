/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:50:16 by tpons             #+#    #+#             */
/*   Updated: 2021/01/13 18:51:08 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
**	coucou
*/

int		handle_pipe(char **inputs, char *input2, char **env)
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
		oldfd = dup(1);
		dup2(fds[1], 1);
		// call of the function "parser_delegator"
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);//return (0);
	else
	{
		if (waitpid(pid, &status, 0) != pid)
			exit(EXIT_FAILURE);//return (0);
		oldfd = dup(0);
		dup2(fds[0], 0);
		// function that convert input2 into the new inputs
	}
	return (1);
}
