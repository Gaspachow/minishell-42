/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_delegator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:47:26 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/14 18:47:00 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int static	handle_basic(char *clean_input, t_data *data, int piped)
{
	char **inputs;
	
	inputs = input_split(clean_input);
	if (!ft_strcmp(inputs[0], "echo"))
		handle_echo(inputs);
	else if (!ft_strcmp(inputs[0], "pwd"))
		handle_pwd();
	else if (!ft_strcmp(inputs[0], "cd"))
		handle_cd(inputs);
	else if (!ft_strcmp(inputs[0], "env"))
		handle_env(data);
	else if (!ft_strcmp(inputs[0], "exit"))
		exit(EXIT_SUCCESS);
	else
		handle_exec(inputs, data);
	if (piped)
		exit (0);
	return (0);
}

static int	parser_pipe(char *input, int pipe_pos, t_data *data) {
	char	*new_input;
	int		space;

	space = 0;
	if (input[pipe_pos - 1] == ' ')
		space = 1;
	new_input = ft_strdup(&input[pipe_pos + 1]);
	input[pipe_pos - space] = '\0';
	return (handle_pipe(input, new_input, data)); 
}

int			parser_delegator(char *input, t_data *data, int piped)
{
	int		i;
	char	quote;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			quote = input[i];
			i++;
			while (input[i] != quote)
				i++;
		}
		else if (input[i] == '|')
			return (parser_pipe(input, i, data));
		i++;
	}
	return (handle_basic(input, data, piped));
}