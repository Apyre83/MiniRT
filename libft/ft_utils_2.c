/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:37:40 by lfresnay          #+#    #+#             */
/*   Updated: 2022/12/04 09:07:21 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_prefix(char *str, char *prefix)
{
	char	*temp;

	temp = ft_strjoin(prefix, str);
	free(str);
	str = 0;
	str = temp;
	return (str);
}

char	*add_suffix(char *str, char *suffix)
{
	char	*temp;

	temp = ft_strjoin(str, suffix);
	free(str);
	str = 0;
	str = temp;
	return (str);
}

void	ft_str_toupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

unsigned int	ft_power_u(unsigned int x, int pow)
{
	if (pow <= 0)
		return (1);
	return (x * ft_power_u(x, pow - 1));
}

int	ft_u_size(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
