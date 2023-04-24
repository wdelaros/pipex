/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:10:09 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/03 20:07:14 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		count;
	size_t	i;

	i = 0;
	count = start;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		while (s[count++] && i < len)
			i++;
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (0);
	if (start >= ft_strlen(s))
		return (str);
	ft_strlcpy(str, &s[start], i + 1);
	return (str);
}
