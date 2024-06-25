/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:59:46 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/25 19:50:04 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void __attribute__((destructor)) foo()
// {
// 	system("leaks pipex");
// }

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	open_io(argc, argv, &pipex);
	pipex.paths = get_path(envp);
	if (!pipex.paths)
		send_error("PATH not found\n");
	pipex.path_args = ft_split(pipex.paths, ':');
	if (pipe(pipex.fd) == -1)
		send_error(PIPE_ERR);
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		send_error(FORK_ERR);
	if (pipex.pid1 == 0)
		cmd1_child(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		send_error(FORK_ERR);
	if (pipex.pid2 == 0)
		cmd2_child(pipex, argv, envp);
	close_pipes(pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	system("leaks pipex");
	return (0);
}
