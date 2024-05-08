/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:14:06 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/08 18:14:07 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define INFILE_OPEN_ERR "Can't open infile\n"
# define OUTFILE_OPEN_ERR "Can't open oufile\n"
# define ARG_ERR "Invalid number of arguments\n"
# define FORK_ERR "Can't fork\n"
# define CLOSE_ERR "Can't close\n"
# define PIPE_ERR "Can't create pipe\n"
# define DUP2_ERR "Can't duplicate file descriptor"
# define CMD_ERR "command not found\n"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	*paths;
	char	**path_args;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	char	*cmd_path;
	char	**cmd_args;
}			t_pipex;

// utils
void		send_error(char *str);
void		open_io(int argc, char **argv, t_pipex *pipex);
char		*get_path(char **envp);
void		send_error(char *str);
void		close_pipes(t_pipex pipex);

// free
void		free_split(char **str);
void		free_main(t_pipex pipex);
void		free_cmd(t_pipex pipex);

// cmd
void		cmd1_child(t_pipex pipex, char **argv, char **envp);
void		cmd2_child(t_pipex pipex, char **argv, char **envp);

#endif