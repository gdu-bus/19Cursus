/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdu-bus- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:25:57 by gdu-bus-          #+#    #+#             */
/*   Updated: 2019/11/07 19:29:06 by gdu-bus-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*ans;

	if (!lst)
		return (NULL);
	if (!f)
		return (lst);
	if (!(ans = ft_lstnew(f(lst->content))))
		return (NULL);
	res = ans;
	while (lst->next)
	{
		lst = lst->next;
		if (!(ans->next = ft_lstnew(f(lst->content))))
			ft_lstclear(&res, del);
		ans = ans->next;
	}
	return (res);
}
