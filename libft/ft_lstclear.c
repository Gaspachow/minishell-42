/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:28:37 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/16 11:43:20 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !*lst || !del)
		return ;
	tmp = *lst;
	tmp2 = tmp;
	while (tmp)
	{
		tmp2 = tmp->next;
		(*del)((void *)tmp->content);
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}
