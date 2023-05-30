/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:53 by jbertin           #+#    #+#             */
/*   Updated: 2023/01/20 08:37:58 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_size_m(int a)
{
	unsigned long long int	i;
	unsigned long long int	b;

	i = 0;
	b = a;
	if (a < 0)
		b = -b;
	while (b > 9)
	{
		b = b / 10;
		i++;
	}
	if (a < 0)
		return ((int)i + 2);
	return ((int)i + 1);
}

char	*ft_itoa(long long int nb)
{
	char			*str;
	int				size;
	int				i;
	long long int	nb2;

	nb2 = nb;
	size = ft_size_m(nb2);
	i = size - 1;
	str = malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (NULL);
	if (nb2 < 0)
	{
		str[0] = '-';
		nb2 = -nb2;
	}
	while (nb2 > 9)
	{
		str[i] = (nb2 % 10 + '0');
		nb2 = nb2 / 10;
		i--;
	}
	str[i] = nb2 % 10 + '0';
	str[size] = '\0';
	return (str);
}
