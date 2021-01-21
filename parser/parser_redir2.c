/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:14:30 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/21 17:39:52 by gsmets           ###   ########.fr       */
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

void	redir_to(char *str, int j, int i, char **input_address)
{
	char	*filename;
	int		fd;

	if (str[j + 1] == ' ')
		j++;
	filename = get_filename(&(str[j + 1]), &j);
	remove_redir_input(input_address, i, j);
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	free(filename);
	dup2(fd, 1);
	parser_redir(input_address);
}

void	redir_to_append(char *str, int j, int i, char **input_address)
{
	char	*filename;
	int		fd;

	j++;
	if (str[j + 1] == ' ')
		j++;
	filename = get_filename(&(str[j + 1]), &j);
	remove_redir_input(input_address, i, j);
	fd = open(filename, O_RDWR | O_CREAT | O_APPEND);
	free(filename);
	dup2(fd, 1);
	parser_redir(input_address);
}

void	redir_from(char *str, int j, int i, char **input_address)
{
	char	*filename;
	int		fd;

	if (str[j + 1] == ' ')
		j++;
	filename = get_filename(&(str[j + 1]), &j);
	remove_redir_input(input_address, i, j);
	fd = open(filename, O_RDONLY);
	free(filename);
	dup2(fd, 0);
	parser_redir(input_address);
}

void	handle_redir(char **input_address, int i)
{
	char	*str;
	int		j;

	str = *input_address;
	j = i;
	if (str[i] == '>' && str[i + 1] != '>')
		redir_to(str, j, i, input_address);
	else if (str[i] == '>' && str[i + 1] == '>')
		redir_to_append(str, j, i, input_address);
	else if (str[i] == '<' && str[i + 1] != '<')
		redir_from(str, j, i, input_address);
}
