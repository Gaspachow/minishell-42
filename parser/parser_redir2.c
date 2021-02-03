/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:14:30 by gsmets            #+#    #+#             */
/*   Updated: 2021/02/03 15:00:25 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		get_name_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' && str[i] != '|' && str[i] != ';' && str[i] != '>' &&
			str[i] != '<' && str[i])
	{
		if (str[i] == '\'')
		{
			while (str[++i] != '\'')
				;
			i++;
		}
		else if (str[i] == '"')
		{
			while (str[++i] != '"')
			{
				if (str[i] == '\\')
					i++;
			}
			i++;
		}
		else
			i++;
	}
	return (i);
}

void	redir_to(char *str, int i, char **input, t_data *data)
{
	char	*filename;
	int		fd;
	int		j;

	j = i;
	if (str[j + 1] == ' ')
		j++;
	filename = get_filename(&(str[j + 1]), &j);
	remove_redir_input(input, i, j);
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	free(filename);
	dup2(fd, 1);
	if (data->fd_out != 1)
		close(data->fd_out);
	data->fd_out = fd;
	parser_redir(input, data);
}

void	redir_to_append(char *str, int i, char **input, t_data *data)
{
	char	*filename;
	int		fd;
	int		j;

	j = i;
	j++;
	if (str[j + 1] == ' ')
		j++;
	filename = get_filename(&(str[j + 1]), &j);
	remove_redir_input(input, i, j);
	fd = open(filename, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	free(filename);
	dup2(fd, 1);
	if (data->fd_out != 1)
		close(data->fd_out);
	data->fd_out = fd;
	parser_redir(input, data);
}

void	redir_from(char *str, int i, char **input, t_data *data)
{
	char	*filename;
	int		fd;
	int		j;

	j = i;
	if (str[j + 1] == ' ')
		j++;
	filename = get_filename(&(str[j + 1]), &j);
	remove_redir_input(input, i, j);
	fd = open(filename, O_RDONLY);
	free(filename);
	dup2(fd, 0);
	if (data->fd_in != 0)
		close(data->fd_in);
	data->fd_in = fd;
	parser_redir(input, data);
}

void	handle_redir(char **input, int i, t_data *data)
{
	char	*str;
	int		j;

	str = *input;
	j = i;
	if (str[i] == '>' && str[i + 1] != '>')
		redir_to(str, i, input, data);
	else if (str[i] == '>' && str[i + 1] == '>')
		redir_to_append(str, i, input, data);
	else if (str[i] == '<' && str[i + 1] != '<')
		redir_from(str, i, input, data);
}
