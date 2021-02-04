/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:58:50 by tpons             #+#    #+#             */
/*   Updated: 2021/02/04 22:47:41 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		change_pwd(t_data *data, char *input)
{
	char	*pwd;
	char	*cwd;
	char	*oldpwd;

	cwd = getcwd(NULL, 0);
	if (!cwd && input && ft_strcmp(".", input) == 0)
	{
		ft_putstr_fd("Error retrieving current directory\n", 2);
		pwd = data->pwd;
		data->pwd = ft_strjoin(pwd, "/.");
		free(pwd);
	}
	if (cwd)
	{
		if (var_index("OLDPWD", data) >= 0)
		{
			pwd = ft_strjoin("PWD=", data->pwd);
			oldpwd = ft_strjoin("OLD", pwd);
			replace_var(oldpwd, data, var_index("OLDPWD=", data));
			free(oldpwd);
			free(pwd);
		}
		else
			data->env = export_env(data->env, "OLDPWD");
		free(data->pwd);
		data->pwd = getcwd(NULL, 0);
		if (var_index("PWD", data) >= 0)
		{
			pwd = ft_strjoin("PWD=", data->pwd);
			replace_var(pwd, data, var_index(pwd, data));
			free(pwd);
		}
		else
		{
			pwd = ft_strjoin("PWD=", data->pwd);
			data->env = export_env(data->env, pwd);
			free(pwd);
		}
	}
	free(cwd);
	return (1);
}
