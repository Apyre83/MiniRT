/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_low_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:17:32 by lfresnay          #+#    #+#             */
/*   Updated: 2022/12/05 12:24:29 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_init_temp_width_low(char *str, t_options *options)
{
	char	*temp;

	if (options->zero_padded && options->precision->is_active == 0
		&& options->left_justify == 0)
	{
		if (str[0] == '0' && str[1] == 'x')
			temp = ft_strdup("0x");
		else
			temp = ft_calloc(1, sizeof(char));
	}
	else
		temp = ft_calloc(1, sizeof(char));
	return (temp);
}

char	*ft_init_temp2_width_low(char *str, t_options *options)
{
	char	*temp2;

	if (options->zero_padded && options->precision->is_active == 0
		&& options->left_justify == 0)
	{
		if (str[0] == '0' && str[1] == 'x')
			temp2 = ft_strdup(str + 2);
		else
			temp2 = ft_strdup(str);
	}
	else
		temp2 = ft_strdup(str);
	return (temp2);
}
