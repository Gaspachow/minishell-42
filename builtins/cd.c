/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:15:19 by tpons             #+#    #+#             */
/*   Updated: 2021/01/12 14:04:03 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		handle_cd(char **args)
{
	if(chdir(args[1]) == -1) //return -1 if it fails to change directory
		return(0); //error
	return (1);
}