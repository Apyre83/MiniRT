/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:44:24 by lfresnay          #+#    #+#             */
/*   Updated: 2022/12/04 09:38:30 by jbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in(char *buffer, char c)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}
