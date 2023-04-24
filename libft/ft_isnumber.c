/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:10:31 by wdelaros          #+#    #+#             */
/*   Updated: 2023/02/02 12:51:29 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == 43 || str[i] == 45)
		{
			i++;
			if (str[i] < 48 || str[i] > 57)
				return (0);
		}
		else if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
