/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:01:43 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/26 20:29:01 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		choose_action(char **inputs, t_data *data)
{
	if (!ft_strcmp(inputs[0], "echo"))
		handle_echo(inputs);
	else if (!ft_strcmp(inputs[0], "pwd"))
		handle_pwd(data);
	else if (!ft_strcmp(inputs[0], "cd"))
		handle_cd(inputs, data);
	else if (!ft_strcmp(inputs[0], "env"))
		handle_env(data->env);
	else if (!ft_strcmp(inputs[0], "exit"))
		exit(EXIT_SUCCESS);
	else if (!ft_strcmp(inputs[0], "export"))
		handle_export(inputs, data);
	else if (!ft_strcmp(inputs[0], "unset"))
		handle_unset(inputs, data);
	else
	{
		handle_exec(inputs, data);
	}
}

void		free_inputs(char **inputs)
{
	int	i;

	i = 0;
	while (inputs[i])
	{
		free(inputs[i]);
		i++;
	}
	free(inputs);
}

void		close_fds(t_data *data)
{
	if (data->fd_in != 0)
	{
		close(data->fd_in);
		data->fd_in = 0;
	}
	if (data->fd_out != 1)
	{
		close(data->fd_out);
		data->fd_out = 1;
	}
}

int			handle_basic(char *clean_input, t_data *data, int piped)
{
	char	**inputs;
	int		oldfd1;
	int		oldfd2;

	oldfd1 = dup(1);
	oldfd2 = dup(0);
	parser_redir(&clean_input, data);
	clean_input = input_cleaner(clean_input);
	inputs = input_split(clean_input);
	free(clean_input);
	choose_action(inputs, data);
	free_inputs(inputs);
	dup2(oldfd1, 1);
	dup2(oldfd2, 0);
	close_fds(data);
	close(oldfd1);
	close(oldfd2);
	if (piped)
		exit(0);
	return (0);
}
