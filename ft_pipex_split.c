/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:28:56 by wdelaros          #+#    #+#             */
/*   Updated: 2023/04/21 07:24:05 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_quotes_and_char(char const *s, char c, size_t *i, \
t_split *data)
{
	while (s[*i])
	{
		if (s[*i] == c)
		{
			data->nb_cols++;
			while (s[*i] && s[*i] == c)
				(*i)++;
			continue ;
		}
		else if ((s[*i] == '"' || s[*i] == '\''))
		{
			data->j = (*i) + 1;
			while (s[data->j] != s[*i] && s[*i])
				data->j++;
			if (s[*i] == s[data->j] && *i != data->j)
				(*i) = data->j;
			else
				exit(1);
		}
		(*i)++;
	}
}

static size_t	ft_cols(char const *s, char c, t_split *data)
{
	size_t	i;

	data->nb_cols = 0;
	if (!s[0])
		return (0);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	check_quotes_and_char(s, c, &i, data);
	if (s[i - 1] != c)
		data->nb_cols++;
	return (data->nb_cols);
}

static size_t	*check_quotes(char **row, size_t *len, size_t i, \
t_split *data)
{
	while ((*row)[data->j] != (*row)[i] && (*row)[data->j])
	{
		data->j++;
		(*len)++;
	}
	return (len);
}

static void	ft_row(char **row, size_t *len, char c, t_split *data)
{
	size_t	i;

	*row += *len;
	*len = 0;
	i = 0;
	while (**row && **row == c)
		(*row)++;
	while ((*row)[i])
	{
		if (((*row)[i] == '"' || (*row)[i] == '\''))
		{
			data->j = i + 1;
			len = check_quotes(row, len, i, data);
			if ((*row)[i] == (*row)[data->j] && i != data->j)
			{
				(*row)++;
				return ;
			}
		}
		else if ((*row)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

char	**ft_pipex_split(char const *s, char c)
{
	t_split	data;
	char	**str;
	char	*row;

	if (!s)
		return (0);
	data.cols = ft_cols(s, c, &data);
	str = ft_calloc(sizeof(char *), (data.cols + 1));
	if (!str)
		return (0);
	row = (char *)s;
	data.i = -1;
	data.len = 0;
	while (++data.i < data.cols)
	{
		ft_row(&row, &data.len, c, &data);
		str[data.i] = ft_calloc(sizeof(char), (data.len + 1));
		if (!str[data.i])
			return (ft_free_null(str));
		ft_strlcpy(str[data.i], row, data.len + 1);
		if ((row + data.len)[0] == '"' || (row + data.len)[0] == '\'')
			row++;
	}
	return (str);
}
