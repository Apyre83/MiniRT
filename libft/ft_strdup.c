/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbertin <jbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:17:19 by lfresnay          #+#    #+#             */
/*   Updated: 2023/01/19 15:49:10 by lfresnay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;

	if (!s)
		return (0);
	result = malloc((ft_strlen((char *) s) + 1) * sizeof(char));
	if (!result)
		return (0);
	(void) ft_strlcpy(result, s, ft_strlen((char *) s) + 1);
	return (result);
}
