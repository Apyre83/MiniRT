/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfresnay <lfresnay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:18:42 by lfresnay          #+#    #+#             */
/*   Updated: 2022/11/09 09:58:32 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		result++;
		while (s[i] == c && c)
			i++;
	}
	return (result);
}

static char	*ft_get_next_word(char const *s, char c)
{
	char	*result;
	int		size;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (0);
	size = 0;
	while (s[size] != c && s[size])
	{
		result[size] = s[size];
		size++;
	}
	result[size] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;
	int		i;
	int		j;

	if (!s)
		return (0);
	size = ft_count_words(s, c);
	result = malloc((size + 1) * sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	while (s[i] == c && s[i])
		i++;
	j = 0;
	while (s[i])
	{
		result[j] = ft_get_next_word(s + i, c);
		i += ft_strlen(result[j]);
		j++;
		while (s[i] == c && c)
			i++;
	}
	result[j] = 0;
	return (result);
}
