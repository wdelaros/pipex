/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:46:45 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/03 20:03:59 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			str = (char *)s;
		++s;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (str);
}
