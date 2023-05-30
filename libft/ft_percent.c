/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:46:18 by lfresnay          #+#    #+#             */
/*   Updated: 2022/12/04 09:06:16 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Pour le flag '%':
 * 	Le flag '-'
 * 	Le flag '0'
 * 	La min width
 */
int	ft_printf_options_percent(char *str, t_options *options)
{
	int		result;
	char	*to_pad;

	result = 0;
	if (options->min_width->is_active)
	{
		to_pad = " ";
		if (options->zero_padded && options->left_justify == 0)
			to_pad = "0";
		if (options->left_justify)
		{
			while (options->min_width->value > ft_strlen(str))
				str = add_suffix(str, to_pad);
		}
		else
		{
			while (options->min_width->value > ft_strlen(str))
				str = add_prefix(str, to_pad);
		}
	}
	ft_putstr_fd(str, 1);
	result = ft_strlen(str);
	free(str);
	return (result);
}

char	*ft_printf_percent(void)
{
	char	*result;

	result = ft_calloc(2, sizeof(char));
	result[0] = '%';
	return (result);
}
