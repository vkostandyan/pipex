/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:14:06 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/25 17:50:38 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>

# define INFILE_OPEN_ERR "\033[1;31mCan't open infile\033[0m\n"
# define OUTFILE_OPEN_ERR "\033[1;31mCan't open oufile\033[0m\n"
# define ARG_ERR "\033[1;31mInvalid number of arguments\033[0m\n"
# define FORK_ERR "\033[1;31mCan't fork\033[0m\n"
# define CLOSE_ERR "\033[1;31mCan't close\033[0m\n"
# define PIPE_ERR "\033[1;31mCan't create pipe\033[0m\n"
# define DUP2_ERR "\033[1;31mCan't duplicate file descriptor\033[0m\n"
# define CMD_ERR "\033[1;31mcommand not found\033[0m\n"

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