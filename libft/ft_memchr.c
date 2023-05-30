/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <lfresnay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:22:32 by lfresnay          #+#    #+#             */
/*   Updated: 2022/11/08 16:45:07 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *) s;
	while (i < n)
	{
		if (temp[i] == (char) c)
			return (temp + i);
		i++;
	}
	return (0);
}
