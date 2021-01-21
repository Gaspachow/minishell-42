/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:03:49 by tpons             #+#    #+#             */
/*   Updated: 2021/01/21 17:16:49 by gsmets           ###   ########.fr       */
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
	int			status;
}				t_data;

int				envlen(char **env);
void			free_env(char **env);
char			**dup_env(char **env);

int				parser_start(char *inputs, t_data *data);
void			quote_len(char **str, int *i, char quote);
char			**input_split(char *str);

int				handle_basic(char *clean_input, t_data *data, int piped);
int				handle_echo(char **args);
int				handle_pwd(void);
int				handle_cd(char **args, t_data *data);
int				handle_exec(char **args, t_data *data);
int				handle_env(char **env);
void			handle_unset(char **inputs, t_data *data);

void			replace_var(char *new_var, t_data *data, int index);
int				var_index(char *name, t_data *data);
int				print_export(char **env);
int				handle_export(char **args, t_data *data);

int				handle_pipe(char *input1, char *input2, t_data *data);
int				parser_delegator(char *input, t_data *data, int piped);
void			parser_variable(char **input_address, int *i, t_data *data);
int				parser_redir(char **input_address);
void			handle_redir(char **input_address, int i);
void			remove_redir_input(char **input_address, int i, int j);
int				get_name_len(char *str);
char			*get_filename(char *str, int *j);
void			input_copy(char *dst, char *src);
char			*input_cleaner(char *str);
void			copy_newsplit(char *src, char *dst, char quote);

#endif
