/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:47:00 by wdelaros          #+#    #+#             */
/*   Updated: 2023/01/10 11:02:00 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	nbr;

	i = 1;
	nbr = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (i < power)
	{
		nbr *= nb;
		i++;
	}
	return (nbr);
}

static char	*ft_convert_decimal(int nb, int base)
{
	int		i;
	int		j;
	char	*num;

	i = ft_intlen(nb, base);
	j = ft_intlen(nb, base) - 1;
	num = ft_calloc(i, sizeof(char));
	while (j >= 0)
	{
		num[j] = (nb % base) + 48;
		nb /= base;
		j--;
	}
	while (i >= 0)
	{
		if (num[i] > 57)
			num[i] = num[i] + 7;
		else
			num[i] = num[i];
		i--;
	}
	return (num);
}

static int	ft_convert_to_decimal(char	*nb, int base)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	num = 0;
	j = ft_strlen(nb) - 1;
	while (nb[i])
	{	
		if (nb[i] >= 97 && nb[i] <= 122)
			num += ((nb[i] - 87) * ft_iterative_power(base, j));
		if (nb[i] >= 65 && nb[i] <= 90)
			num += ((nb[i] - 55) * ft_iterative_power(base, j));
		else
			num += ((nb[i] - 48) * ft_iterative_power(base, j));
		i++;
		j--;
	}
	return (num);
}

char	*ft_convertbase(char *nb, int initbase, int finalbase)
{
	char	*nbr;
	int		num;

	if (!nb)
		return (0);
	if (initbase == finalbase)
		return (nb);
	num = 0;
	if (initbase != 10)
		num = ft_convert_to_decimal(nb, initbase);
	if (initbase == 10)
	{
		ft_atoi(nb);
		nbr = ft_convert_decimal(num, finalbase);
	}
	else
		nbr = ft_convert_decimal(num, finalbase);
	return (nbr);
}
