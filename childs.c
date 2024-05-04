/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:46:28 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/04 17:34:22 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void first_child(t_pipex pipex, char **argv, char **envp)
{
    dup2(pipex.fd[1], 1);
    close(pipex.fd[0]);
    dup2(pipex.infile, 0);
    pipex.cmd_args = ft_split(argv[2], ' ');
    pipex.cmd_path = get_command_path(pipex.path_args, pipex.cmd_args[0]);
    if (!pipex.cmd_path)
    {
        ft_putstr_fd("Command not found\n", 2);
        free_for_child(pipex);
        exit (1);   
    }
    execve(pipex.cmd_path, pipex.cmd_args, envp);
}

void second_child(t_pipex pipex, char **argv, char **envp)
{
    dup2(pipex.fd[0], 0);
    close(pipex.fd[1]);
    dup2(pipex.outfile, 1);
    pipex.cmd_args = ft_split(argv[3], ' ');
    pipex.cmd_path = get_command_path(pipex.path_args, pipex.cmd_args[0]);
    if (!pipex.cmd_path)
    {
        ft_putstr_fd("Command not found\n", 2);
        free_for_child(pipex);
        exit (1);
    }
    execve(pipex.cmd_path, pipex.cmd_args, envp);
}
