/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:30:57 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/03 19:53:52 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	while (s[n])
		n++;
	while (i++ <= n)
	{
		if (*str++ == (char)c)
			return (--str);
	}
	return (0);
}
