/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:18:35 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/28 18:52:31 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	send_error(char *str)
{
	if (errno == 0)
		ft_putstr_fd(str, 2);
	else
		perror(str);
	exit(1);
}

void	open_io(int argc, char **argv, t_pipex *pipex)
{
	if (argc != 5)
		send_error(ARG_ERR);
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->infile == -1)
		send_error(INFILE_OPEN_ERR);
	if (pipex->outfile == -1)
		send_error(OUTFILE_OPEN_ERR);
}

char	*get_path(char **envp)
{
	while (*envp && ft_strncmp(*envp, "PATH", 4) != 0)
		envp++;
	if (*envp)
		return (*envp + 5);
	return (NULL);
}

void	close_pipes(t_pipex pipex)
{
	int	c1;
	int	c2;

	c1 = close(pipex.fd[0]);
	c2 = close(pipex.fd[1]);
	if (c1 == -1 || c2 == -1)
		send_error(CLOSE_ERR);
}
