/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:23:49 by wdelaros          #+#    #+#             */
/*   Updated: 2023/04/17 07:27:20 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_recalloc(void *new, size_t count, size_t size)
{
	if (new)
		free(new);
	new = malloc((size * count));
	if (!new)
		return (0);
	ft_bzero(new, count * size);
	return (new);
}
