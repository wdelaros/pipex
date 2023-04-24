/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:47:35 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/03 19:46:08 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str1;
	size_t			i;

	i = 0;
	str1 = b;
	if (!b)
		return (NULL);
	while (i < len)
		str1[i++] = c;
	return (b);
}
