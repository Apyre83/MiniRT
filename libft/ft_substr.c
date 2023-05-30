/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <lfresnay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:46:34 by lfresnay          #+#    #+#             */
/*   Updated: 2022/11/09 21:36:34 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;
	unsigned int	size;

	if (!s || start > (unsigned int) ft_strlen((char *)s))
	{
		result = malloc(sizeof(char));
		result[0] = '\0';
		return (result);
	}
	size = 0;
	if (start >= (unsigned) ft_strlen((char *) s))
		return (malloc(0));
	while (s[size + start] && size < len)
		size++;
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (0);
	i = -1;
	while (++i < size)
		result[i] = s[start + i];
	result[i] = '\0';
	return (result);
}
