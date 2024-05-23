/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:45:30 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/16 20:05:12 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command_path(char **path_args, char *cmd)
{
	char	*command;

	while (*path_args)
	{
		command = ft_join(*path_args, cmd);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		path_args++;
	}
	return (NULL);
}

void	cmd1_child(t_pipex pipex, char **argv, char **envp)
{
	if (dup2(pipex.fd[1], STDOUT_FILENO) == -1)
		send_error(DUP2_ERR);
	if (close(pipex.fd[0]) == -1)
		send_error(CLOSE_ERR);
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		send_error(DUP2_ERR);
	if (close(pipex.fd[1]) == -1)
		send_error(CLOSE_ERR);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd_path = get_command_path(pipex.path_args, pipex.cmd_args[0]);
	if (!pipex.cmd_path)
	{
		free_cmd(pipex);
		send_error(CMD_ERR);
	}
	execve(pipex.cmd_path, pipex.cmd_args, envp);
	// execve(pipex.cmd_args[0], pipex.cmd_args, envp);
}

void	cmd2_child(t_pipex pipex, char **argv, char **envp)
{
	if (close(pipex.fd[0] == -1))
		send_error(CLOSE_ERR);
	if (dup2(pipex.fd[0], STDIN_FILENO) == -1)
		send_error(DUP2_ERR);
	if (close(pipex.fd[1]) == -1)
		send_error(CLOSE_ERR);
	if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
		send_error(DUP2_ERR);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd_path = get_command_path(pipex.path_args, pipex.cmd_args[0]);
	if (!pipex.cmd_path)
	{
		free_cmd(pipex);
		send_error(CMD_ERR);
	}
	execve(pipex.cmd_path, pipex.cmd_args, envp);
	// execve(pipex.cmd_args[0], pipex.cmd_args, envp);
}
