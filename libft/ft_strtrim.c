/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <lfresnay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:04:17 by lfresnay          #+#    #+#             */
/*   Updated: 2022/11/08 19:27:44 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*result;

	if (!s1)
		return (0);
	start = 0;
	end = ft_strlen((char *) s1);
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	while (end > start && ft_isset(s1[end - 1], set))
		end--;
	result = malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (i + start < end)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
