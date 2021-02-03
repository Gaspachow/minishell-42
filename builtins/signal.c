/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:32:04 by tpons             #+#    #+#             */
/*   Updated: 2021/02/03 14:28:54 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 130;
		if (g_user_input)
			free(g_user_input);
		g_user_input = ft_strdup("\0");
		write(2, "\n", 1);
		ft_putstr_fd("minishell> ", 2);
	}
	else if (sig == SIGQUIT)
		write(2, "\b\b  \b\b", 6);
}

void	sig_init(void)
{
	if (signal(SIGINT, handle_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
	else if (signal(SIGQUIT, handle_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
}

void	handle_exec_sig(int sig)
{
	if (sig == SIGINT)
	{
		if (g_user_input)
			free(g_user_input);
		g_status = 130;
		g_quit = 1;
		write(2, "\n", 1);
	}
	else if (sig == SIGQUIT)
	{
		g_status = 131;
		ft_putstr_fd("Exit (core dumped)\n", 2);
	}
}

void	sig_exec_init(void)
{
	if (signal(SIGINT, handle_exec_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
	else if (signal(SIGQUIT, handle_exec_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
}
