/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:18:49 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/03 19:42:54 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!dst || !src)
		return (NULL);
	if (dst != NULL || src != NULL)
	{
		if (dst < src)
		{
			d = dst;
			s = src;
			while (len--)
				*d++ = *s++;
		}
		else
		{
			d = dst + (len - 1);
			s = src + (len - 1);
			while (len--)
				*d-- = *s--;
		}
	}
	return (dst);
}
