/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:15:19 by tpons             #+#    #+#             */
/*   Updated: 2021/01/16 16:58:33 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
**	In handle_cd :
**		chdir returns -1 if it fails to change directory
**		return(0) === error
*/

int		handle_cd(char **args, t_data *data)
{
	char	*buf;
	char	*pwd;
	char	*oldpwd;

	if (chdir(args[1]) == -1 && var_exists("PWD=", data) &&
	var_exists("OLDPWD=", data))
		return (0);
	else
	{
		oldpwd = ft_strjoin("OLD", data->env[var_exists("PWD=", data)]);
		replace_var(oldpwd, data, var_exists("OLDPWD=", data));
		free(oldpwd);
		buf = getcwd(NULL, 0);
		pwd = ft_strjoin("PWD=", buf);
		free(buf);
		replace_var(pwd, data, var_exists(pwd, data));
	}
	return (1);
}
