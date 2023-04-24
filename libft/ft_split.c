/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 06:46:56 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/03 11:55:08 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_null(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	ft_cols(char const *s, char c)
{
	size_t	i;
	size_t	nb_cols;

	nb_cols = 0;
	if (!s[0])
		return (0);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_cols++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_cols++;
	return (nb_cols);
}

static void	ft_row(char **row, size_t *len, char c)
{
	size_t	i;

	*row += *len;
	*len = 0;
	i = 0;
	while (**row && **row == c)
		(*row)++;
	while ((*row)[i])
	{
		if ((*row)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*row;
	size_t	i;
	size_t	len;
	size_t	cols;

	if (!s)
		return (0);
	cols = ft_cols(s, c);
	str = ft_calloc(sizeof(char *), (cols + 1));
	if (!str)
		return (0);
	row = (char *)s;
	i = 0;
	len = 0;
	while (i < cols)
	{
		ft_row(&row, &len, c);
		str[i] = ft_calloc(sizeof(char), (len + 1));
		if (!str[i])
			return (ft_free_null(str));
		ft_strlcpy(str[i], row, len + 1);
		i++;
	}
	return (str);
}
