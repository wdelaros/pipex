/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:31:34 by wdelaros          #+#    #+#             */
/*   Updated: 2023/04/20 13:30:51 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	**path;
	char	**envp;
	char	*cmdpath;
	int		*quotes;
	size_t	i;
	size_t	j;
}					t_pipex;

typedef struct s_split
{
	int		quotes;
	size_t	len;
	size_t	cols;
	size_t	nb_cols;
	size_t	i;
	size_t	j;
}					t_split;

t_pipex	init_value(char *envp[]);
void	parent(char *argv[], int *pfd, t_pipex *data);
char	**findpath(t_pipex *data);
void	ft_verif_file(t_pipex *data, char *argv[]);
void	ft_error(char *error, char *str, t_pipex *data);
void	free_all(t_pipex *data);
char	**ft_pipex_split(char const *s, char c);
#endif
