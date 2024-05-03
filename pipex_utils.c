/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 20:06:40 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/03 22:22:56 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_command(char **path_args, char *cmd)
{
    char *tmp;
    char *command;

    while (*path_args)
    {
        tmp = ft_strjoin(*path_args, "/");
        command = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(command, X_OK) == 0)
        {
            return (command);
        }
        path_args++;
    }
    return (NULL);
}

char *get_path(char **envp)
{
    while (ft_strncmp(*envp, "PATH", 4) != 0)
        envp++;
    return (*envp + 5);
}

void close_pipes(t_pipex pipex)
{
    close(pipex.fd[0]);
    close(pipex.fd[1]);
}
