/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:03:49 by tpons             #+#    #+#             */
/*   Updated: 2021/01/13 14:01:45 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <term.h>
# include <curses.h>
# include <termios.h>
# include <stdint.h>
# include <sys/ioctl.h>

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include "libft/libft.h"

typedef	struct	s_data
{
	char		*user_input;
	char		*clean_input;
	char		**inputs;
	char		**env;
}				t_data;

t_data			init_data(char **env);
int				parser(char *inputs, char **env);
char			**input_split(char const *str);

int				handle_echo(char **args);
int				handle_pwd(void);
int				handle_cd(char **args);
int				handle_exec(char **args, char **env);

#endif
