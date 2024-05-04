/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:20:37 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/04 17:34:12 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pipex
{
    char *paths;
    char **path_args;
    int infile;
    int outfile;
    
    int fd[2];
    pid_t pid1;
    pid_t pid2;
    
    char *cmd_path;
    char **cmd_args;
}           t_pipex;

// helpers
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_join(char const *s1, char const *s2);
int	    ft_putstr_fd(char *s, int fd);

// free
void	free_split(char **str);
void    free_for_parent(t_pipex pipex);
void    free_for_child(t_pipex pipex);

// valid
int		check_command(char *cmd, char **envp);

// childs
void first_child(t_pipex pipex, char **argv, char **envp);
void second_child(t_pipex pipex, char **argv, char **envp);


//
char    *get_path(char **envp);
void    close_pipes(t_pipex pipex);
char    *get_command_path(char **path_args, char *cmd);


#endif