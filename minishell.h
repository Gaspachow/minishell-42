/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:03:49 by tpons             #+#    #+#             */
/*   Updated: 2021/01/15 18:29:04 by gsmets           ###   ########.fr       */
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
	char		**env;
}				t_data;

int				envlen(char **env);
void			free_env(char **env);
void			dup_env(t_data *data, char **env);

int				parser_start(char *inputs, t_data *data);
char			**input_split(char const *str);

int				handle_echo(char **args);
int				handle_pwd(void);
int				handle_cd(char **args);
int				handle_exec(char **args, t_data *data);
int				handle_env(t_data *data);
int				handle_export(char **args, t_data *data);
int				handle_pipe(char *input1, char *input2, t_data *data);
int				parser_delegator(char *input, t_data *data, int piped);
void			parser_variable(char **input_address, int *i, t_data *data);

#endif
