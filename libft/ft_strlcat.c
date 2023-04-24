/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:40:45 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/03 19:58:07 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	if (!dst || !src)
		return (0);
	len = ft_strlen(dst);
	if (dstsize <= len)
		return (dstsize + ft_strlen(src));
	dstsize -= len + 1;
	while (*src && dstsize-- > 0)
	{
		dst[len++] = *src++;
		dst[len] = 0;
	}
	return (len + ft_strlen(src));
}
