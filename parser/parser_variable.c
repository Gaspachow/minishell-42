/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:35:13 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/16 13:00:01 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		get_name_len(char *str)
{
	int len;

	len = 0;
	while (ft_isalnum(str[len]) || str[len] == '_')
		len++;
	if (!len && str[len] == '?')
		return (1);
	return (len);
}

static char		*get_value(char *name, t_data *data)
{
	char	**env;
	int		i;
	int		j;
	int		k;

	env = data->env;
	i = 0;
	while (env[i])
	{
		j = 0;
		k = 0;
		while (env[i][j] && env[i][j] != '=' && env[i][j] == name[k])
		{
			k++;
			j++;
		}
		if (env[i][j] == '=' && !name[k])
			return (ft_strdup(&env[i][j + 1]));
		i++;
	}
	return (NULL);
}

void			parser_variable(char **input_address, int *i, t_data *data)
{
	int		len;
	char	*var_value;
	char	*var_name;
	char	*new_input;
	char	*tmp;

	len = get_name_len(&(input_address[0][*i + 1]));
	var_name = ft_substr(*input_address, *i + 1, len);
	if (len == 1 && input_address[0][*i + 1])
		var_value = ft_strdup(ft_itoa(data->status));
	else if (len)
		var_value = get_value(var_name, data);
	else
		var_value = ft_strdup("$");
	free(var_name);
	new_input = ft_substr(*input_address, 0, *i);
	tmp = ft_strjoin(new_input, var_value);
	free(new_input);
	new_input = ft_strjoin(tmp, &(input_address[0][*i + 1 + len]));
	len = ft_strlen(var_value);
	free(var_value);
	free(*input_address);
	*input_address = new_input;
	*i += len - 1;
}
