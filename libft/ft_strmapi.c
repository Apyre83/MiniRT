/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <lfresnay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:00:29 by lfresnay          #+#    #+#             */
/*   Updated: 2022/11/08 19:20:47 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*result;
	unsigned int	size;
	unsigned int	i;

	if (!s)
		return (0);
	size = (unsigned int) ft_strlen((char *) s);
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (i < size)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
