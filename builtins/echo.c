/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:10:26 by gsmets            #+#    #+#             */
/*   Updated: 2021/01/11 16:53:41 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Expects an array of strings, of which the first is "echo" and last is NULL
int handle_echo(char **args)
{
    int i;
    int newline;

    i = 1;
    newline = 0;
    if (!ft_strcmp(args[1], "-n") && i++)
        newline = 1;
    while(args[i])
    {
        // must change to fd
        write(1, args[1], ft_strlen(args[1]));
        if (newline && args[i + 1])
            write(1, " ", 1);
    }
}