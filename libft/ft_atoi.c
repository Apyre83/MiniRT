/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:42:08 by jbertin           #+#    #+#             */
/*   Updated: 2023/01/20 08:30:54 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_sp_signs(int *ptr_i, const char *str, int *ptr_minus)
{
	int	minus;
	int	i;

	i = 0;
	minus = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+' || str[i] == '-')
		&& (str[i + 1] == '+' || str[i + 1] == '-'))
		return (9);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			minus++;
			i++;
		}
		else
			i++;
	}
	*ptr_i = i;
	*ptr_minus = minus;
	return (0);
}

long long int	ft_atoi(const char *str)
{
	int				i;
	long long int	nb;
	int				minus;

	i = 0;
	nb = 0;
	minus = 0;
	if (check_sp_signs(&i, str, &minus) == 9)
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (minus % 2 == 1)
		nb = -nb;
	return (nb);
}
