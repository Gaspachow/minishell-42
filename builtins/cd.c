/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:15:19 by tpons             #+#    #+#             */
/*   Updated: 2021/01/30 12:33:11 by tpons            ###   ########.fr       */
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
		return (0);//error
	oldpwd = ft_strjoin("OLD", data->env[var_index("PWD=", data)]);
	replace_var(oldpwd, data, var_index("OLDPWD=", data));
	free(oldpwd);
	buf = getcwd(NULL, 0);
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
		return (0);//error
	oldpwd = ft_strjoin("OLD", data->env[var_index("PWD=", data)]);
	replace_var(oldpwd, data, var_index("OLDPWD=", data));
	free(oldpwd);
	buf = getcwd(NULL, 0);
	if (!buf)
		exit(EXIT_FAILURE); /// safety if getcwd malloc failed
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
		return (0);//error
	oldpwd = ft_strjoin("OLD", data->env[var_index("PWD=", data)]);
	replace_var(oldpwd, data, var_index("OLDPWD=", data));
	free(oldpwd);
	buf = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", buf);
	free(buf);
	replace_var(pwd, data, var_index(pwd, data));
	free(pwd);
	return (1);
}

int		handle_cd(char **args, t_data *data)
{
	if (args[1] && args[2])
	{
		ft_putstr_fd("bash: cd: too many arguments\n", 2);
		return (0);
	}
	else if (!args[1])
	{
		if (!cd_alone(data))
			return (0); //ft_putstr("cd: HOME is undefined\n");
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		if (!cd_minus(data))
			return (0);
	}
	else
	{
		if (!cd_path(args, data))
			return (0);
	}
	return (1);
	// need support error 
}
