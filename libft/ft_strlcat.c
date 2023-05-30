/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:35:49 by lfresnay          #+#    #+#             */
/*   Updated: 2022/12/04 09:06:59 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sizedst;

	if (!dst && size == 0)
		return (0);
	sizedst = ft_strlen(dst);
	i = 0;
	if (size <= sizedst)
		return (size + ft_strlen((char *)src));
	while (src[i] && sizedst + i < size - 1 && size > 0)
	{
		dst[sizedst + i] = src[i];
		i++;
	}
	dst[sizedst + i] = '\0';
	return (sizedst + ft_strlen((char *) src));
}
