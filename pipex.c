/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:13:48 by wdelaros          #+#    #+#             */
/*   Updated: 2023/04/20 13:52:06 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, t_pipex *data)
{
	char	**fcmd;
	char	*str;
	int		i;

	i = 0;
	fcmd = ft_pipex_split(cmd, 32);
	while (data->path[i])
	{
		data->cmdpath = ft_strjoin(data->path[i], fcmd[0]);
		if (!access(data->cmdpath, F_OK))
			break ;
		if (data->path[i + 1])
			free(data->cmdpath);
		i++;
	}
	if (execve(data->cmdpath, fcmd, data->envp) == -1)
	{
		free(data->cmdpath);
		str = ft_strdup(fcmd[0]);
		ft_free_null(fcmd);
		ft_error("command not found: ", str, data);
	}
}

void	child(char *argv[], int *pfd, t_pipex *data)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	dup2(fd, 0);
	close(fd);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	exec(argv[2], data);
}

void	parent(char *argv[], int *pfd, t_pipex *data)
{
	int	fd;

	fd = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, S_IRWXU);
	dup2(fd, 1);
	close(fd);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	exec(argv[3], data);
}

void	run_cmd(t_pipex data, char *argv[])
{
	int		pfd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pfd) == -1)
		ft_error("Pipex: ", "pipe", &data);
	pid1 = fork();
	if (pid1 == -1)
		ft_error("Pipex: ", "fork(pid1)", &data);
	if (!pid1)
		child(argv, pfd, &data);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("pipex:", "fork(pid2)", &data);
	if (!pid2)
		parent(argv, pfd, &data);
	close(pfd[0]);
	close(pfd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	data;

	if (argc != 5)
		ft_error("Wrong input: ", ft_strdup("./pipex file1 cmd1 cmd2 file2") \
		, NULL);
	data = init_value(envp);
	ft_verif_file(&data, argv);
	run_cmd(data, argv);
	free_all(&data);
	return (0);
}
