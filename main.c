/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:06:44 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/03 22:23:55 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;
    (void)argv;
    (void)argc;

    // if (argc != 5)
    //     return (ft_putstr_fd("Invalid number of arguments\n", 2));
    // pipex.infile = open(argv[1], O_RDONLY);
    // if (pipex.infile < 0)
    //     return (ft_putstr_fd("Error while opening infile\n", 2));
    // pipex.outfile = open(argv[4], O_RDWR | O_CREAT);
    // if (pipex.outfile < 0)
    //     return (ft_putstr_fd("Error while creating outfile\n", 2));
    pipex.paths = get_path(envp);
    pipex.path_args = ft_split(pipex.paths, ':');

    char *temp = get_command(pipex.path_args, argv[1]);
    printf("%s\n", temp);
    // if (pipe(pipex.fd) == -1)
    //     return (ft_putstr_fd("Error while creating pipe\n", 2));
    // pipex.pid1 = fork();
    // if (pipex.pid1 == 0)
    //     child1();
    // pipex.pid2 = fork();
    // if (pipex.pid2 == 0)
    //     child2();
    // close_pipes(pipex);
    return (0);
}
