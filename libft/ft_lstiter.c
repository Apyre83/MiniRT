/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <lfresnay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:04:51 by lfresnay          #+#    #+#             */
/*   Updated: 2022/11/08 19:14:50 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	t_list	*temp;

	temp = lst;
	if (!lst)
		return ;
	while (temp->next)
	{
		(*f)(temp->content);
		temp = temp->next;
	}
	(*f)(temp->content);
}
