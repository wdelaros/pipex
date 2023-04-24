/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 08:49:49 by wdelaros          #+#    #+#             */
/*   Updated: 2023/04/20 13:35:12 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_pipex *data)
{
	if (data->path)
		ft_free_null(data->path);
}

void	ft_error(char *error, char *str, t_pipex *data)
{
	ft_putstr_fd (error, 2);
	ft_putendl_fd (str, 2);
	if (str)
		free(str);
	if (data)
	{
		free_all(data);
	}
	exit (1);
}

void	ft_verif_file(t_pipex *data, char *argv[])
{
	int	pfd[2];
	int	fd;

	fd = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	close(fd);
	if (access(argv[4], W_OK) && access(argv[1], R_OK))
	{
		ft_putstr_fd("permission denied: ", 2);
		ft_putendl_fd(argv[4], 2);
		ft_error("permission denied: ", ft_strdup(argv[1]), data);
	}
	else if (access(argv[4], W_OK))
		ft_error("permission denied: ", ft_strdup(argv[4]), data);
	else if (access(argv[1], R_OK))
	{
		ft_putstr_fd("permission denied: ", 2);
		ft_putendl_fd(argv[1], 2);
		pipe(pfd);
		parent(argv, pfd, data);
	}
}

char	**findpath(t_pipex *data)
{
	int		i;

	i = 0;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], "PATH=", 5))
			break ;
		i++;
	}
	if (data->envp[i])
		data->path = ft_split(data->envp[i] + 5, ':');
	else
		ft_error("pipex: ", ft_strdup("No environment"), NULL);
	if (!data->path)
		perror("Error");
	return (data->path);
}

t_pipex	init_value(char *envp[])
{
	t_pipex	data;
	int		i;

	data.envp = envp;
	data.path = findpath(&data);
	i = 0;
	while (data.path[i])
	{
		data.path[i] = ft_fstrjoin(data.path[i], "/");
		i++;
	}
	return (data);
}
