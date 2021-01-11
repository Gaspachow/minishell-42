/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:18:48 by gsmets            #+#    #+#             */
/*   Updated: 2019/10/17 16:10:14 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*alst;
	t_list	*newlst;
	void	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = (*f)(lst->content);
	if (!(newlst = ft_lstnew(tmp)))
		return (NULL);
	alst = newlst;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst->content);
		if (!(newlst->next = ft_lstnew(tmp)))
		{
			ft_lstclear(&alst, del);
			return (NULL);
		}
		newlst = newlst->next;
		lst = lst->next;
	}
	return (alst);
}
