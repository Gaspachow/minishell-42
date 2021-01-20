/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:35:13 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/20 17:51:16 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*get_filename(char *str, int *j)
{
	int		i;
	int		k;
	char	*filename;

	i = 0;
	while (str[i] != ' ' && str[i] != '|' && str[i] != ';' && str[i] != '>' &&
			str[i] != '<' && str[i])
	{
		i++;
	}
	*j += i;
	filename = malloc(i * sizeof(char));
	if (!filename)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i] != ' ' && str[i] != '|' && str[i] != ';' && str[i] != '>' &&
			str[i] != '<' && str[i])
	{
		if (str[i] != '"' && str[i] != '\'')
			filename[k++] = str[i];
		i++;
	}
	filename[k] = '\0';
	return (filename);
}

void		remove_redir_input(char **input_address, int i, int j)
{
	char *tmp;
	char *new_input;

	tmp = ft_substr(input_address[0], 0, i);
	new_input = ft_strjoin(tmp, &(input_address[0][j + 1]));
	free(tmp);
	free(*input_address);
	*input_address = new_input;
}

void		parser_redir_quotes(char *str, int *i, char quote)
{
	int slash_count;

	while (str[*i] != quote)
	{
		slash_count = 0;
		while (str[*i] == '\\' && quote == '"')
		{
			slash_count++;
			(*i)++;
		}
		if (slash_count && !(slash_count % 2))
			(*i)--;
		(*i)++;
	}
}

int			parser_redir(char **input_address)
{
	int		i;
	char	*str;
	char	quote;

	i = -1;
	str = *input_address;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i];
			i++;
			parser_redir_quotes(str, &i, quote);
		}
		if (str[i] == '>' || str[i] == '<')
		{
			handle_redir(input_address, i);
			return (1);
		}
	}
	return (0);
}
