/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:10:26 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/11 17:16:40 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// Expects an array of strings, of which the first is "echo" and last is NULL
int handle_echo(char **args)
{
    int i;
    int nFlag;

    i = 1;
    nFlag = 0;
    while (args[i] && !ft_strcmp(args[i], "-n") && i++)
        nFlag = 1;
    while(args[i])
    {
        // must change to fd
        write(1, args[i], ft_strlen(args[i]));
        if (args[i + 1])
            write(1, " ", 1);
        i++;
    }
    if (!nFlag)
        write(1, "\n", 1);
    return (0);
}