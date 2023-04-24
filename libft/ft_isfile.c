/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 07:29:16 by wdelaros          #+#    #+#             */
/*   Updated: 2023/01/30 10:25:03 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isfile(char *file)
{
	if (!file)
		return (0);
	else if (!ft_strncmp(ft_strnstr(file, ".txt", 5), ".txt", 5) && \
			!ft_strncmp(ft_strrchr(file, 46), ".txt", 5))
		return (1);
	else if (!ft_strncmp(ft_strnstr(file, ".fdf", 5), ".fdf", 5) && \
	!ft_strncmp(ft_strrchr(file, 46), ".fdf", 5))
		return (2);
	else if (!ft_strncmp(ft_strnstr(file, ".ber", 5), ".ber", 5) && \
	!ft_strncmp(ft_strrchr(file, 46), ".ber", 5))
		return (3);
	else if (!ft_strncmp(ft_strnstr(file, ".ans", 5), ".ans", 5) && \
	!ft_strncmp(ft_strrchr(file, 46), ".ans", 5))
		return (4);
	return (0);
}
