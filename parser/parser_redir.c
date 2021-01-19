/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:35:13 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/19 19:05:39 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		*get_filename(char *str, int *j)
{
	int i;
	int k;
	char *filename;

	i = 0;
	while (str[i] != ' ' && str[i] != '|' && str[i] != ';' && str[i] != '>' && str[i] != '<' && str[i])
	{
		i++;
	}
	*j += i;
	filename = malloc(i * sizeof(char));
	i = 0;
	k = 0;
	while (str[i] != ' ' && str[i] != '|' && str[i] != ';' && str[i] != '>' && str[i] != '<' && str[i])
	{
		if (str[i] != '"' && str[i] != '\'')
			filename[k++] = str[i];
		i++;
	}
	filename[k] = '\0';
	return (filename);
}

static void		remove_redir_input(char **input_address, int i, int j)
{
	char *tmp;
	char *new_input;

	tmp = ft_substr(input_address[0], 0, i);
	new_input = ft_strjoin(tmp, &(input_address[0][j + 1]));
	free(tmp);
	free(*input_address);
	*input_address = new_input;
}

void		handle_redir(char **input_address, int i)
{
	char	*str;
	int		j;
	char	*filename;
	int 	fd;

	str = *input_address;
	j = i;
	if (str[i] == '>' && str[i + 1] != '>')
	{
		if (str[j + 1] == ' ')
			j++;
		filename = get_filename(&(str[j + 1]), &j);
		remove_redir_input(input_address, i, j);
		fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		free(filename);
		dup2(fd, 1);
		parser_redir(input_address);
	}
	if (str[i] == '>' && str[i + 1] == '>')
	{
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
	if (str[i] == '<' && str[i + 1] != '<')
	{
		if (str[j + 1] == ' ')
			j++;
		filename = get_filename(&(str[j + 1]), &j);
		remove_redir_input(input_address, i, j);
		fd = open(filename, O_RDONLY);
		free(filename);
		dup2(fd, 0);
		parser_redir(input_address);
	}
}

int			parser_redir(char **input_address)
{
	int 	i;
	char 	*str;
	char 	quote;
	int		slash_count;

	i = -1;
	str = *input_address;
	while (str[++i])
	{	
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i];
			i++;
			while (str[i] != quote)
			{
				slash_count = 0;
				while (str[i] == '\\' && quote == '"')
				{
					slash_count++;
					i++;
				}
				if (slash_count && !(slash_count % 2))
					i--;
				i++;
			}
		}
		if (str[i] == '>' || str[i] == '<')
			{
				handle_redir(input_address, i);
				return (1);
			}
	}
	return (0);
}
