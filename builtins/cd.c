/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:15:19 by tpons             #+#    #+#             */
/*   Updated: 2021/01/30 13:32:58 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
**	In handle_cd :
**		chdir returns -1 if it fails to change directory
**		return(0) === error
*/

int		cd_minus(t_data *data)
{
	char	*buf;
	char	*pwd;
	char	*oldpwd;

	if (var_index("PWD=", data) < 0 || var_index("OLDPWD=", data) < 0 ||
	chdir((strchr(data->env[var_index("OLDPWD=", data)], '=') + 1)) == -1)
		return (0);
	oldpwd = ft_strjoin("OLD", data->env[var_index("PWD=", data)]);
	replace_var(oldpwd, data, var_index("OLDPWD=", data));
	free(oldpwd);
	buf = getcwd(NULL, 0);
	if (!buf)
		exit(EXIT_FAILURE);
	pwd = ft_strjoin("PWD=", buf);
	free(buf);
	replace_var(pwd, data, var_index(pwd, data));
	free(pwd);
	return (1);
}

int		cd_alone(t_data *data)
{
	char	*buf;
	char	*pwd;
	char	*oldpwd;

	if (var_index("HOME=", data) < 0 ||
	chdir((strchr(data->env[var_index("HOME=", data)], '=') + 1)) == -1 ||
	var_index("PWD=", data) < 0 || var_index("OLDPWD=", data) < 0)
		return (0);
	oldpwd = ft_strjoin("OLD", data->env[var_index("PWD=", data)]);
	replace_var(oldpwd, data, var_index("OLDPWD=", data));
	free(oldpwd);
	buf = getcwd(NULL, 0);
	if (!buf)
		exit(EXIT_FAILURE);
	pwd = ft_strjoin("PWD=", buf);
	free(buf);
	replace_var(pwd, data, var_index(pwd, data));
	free(pwd);
	return (1);
}

int		cd_path(char **args, t_data *data)
{
	char	*buf;
	char	*pwd;
	char	*oldpwd;

	if (chdir(args[1]) == -1 || var_index("PWD=", data) < 0 ||
	var_index("OLDPWD=", data) < 0)
		return (0);
	oldpwd = ft_strjoin("OLD", data->env[var_index("PWD=", data)]);
	replace_var(oldpwd, data, var_index("OLDPWD=", data));
	free(oldpwd);
	buf = getcwd(NULL, 0);
	if (!buf)
		exit(EXIT_FAILURE);
	pwd = ft_strjoin("PWD=", buf);
	free(buf);
	replace_var(pwd, data, var_index(pwd, data));
	free(pwd);
	return (1);
}

void	handle_cd(char **args, t_data *data)
{
	if (args[1] && args[2])
		return (error_sentence("cd: too many arguments\n", 1));
	else if (!args[1])
	{
		if (!cd_alone(data))
			return (error_sentence("cd: HOME||PWD||OLDPWD: is undefined\n", 1));
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		if (!cd_minus(data))
			return (error_sentence("cd: OLDPWD||PWD is undefined\n", 1));
	}
	else
	{
		if (!cd_path(args, data))
			return (error_sentence("cd: no such file or directory\n", 1));
	}
	g_status = 0;
}
