/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <lfresnay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:06:41 by lfresnay          #+#    #+#             */
/*   Updated: 2022/11/08 19:01:59 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*new;
	t_list	*tempnew;
	t_list	*templst;

	templst = lst;
	new = 0;
	while (templst)
	{
		tempnew = ft_lstnew((*f)(templst->content));
		if (!tempnew)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, tempnew);
		templst = templst->next;
	}
	return (new);
}
