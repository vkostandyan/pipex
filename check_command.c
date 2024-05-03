/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:16:00 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/03 19:35:59 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	find_path_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	**prepare_and_split(char *str)
{
	int		i;
	int		len;
	char	**split;

	len = ft_strlen(str);
	i = 0;
	while (i < len - 5)
	{
		str[i] = str[i + 5];
		i++;
	}
	str[i] = '\0';
	split = ft_split(str, ':');
	if (!split)
		return (NULL);
	return (split);
}

char *find_path(char *cmd, char **envp)
{
	int		line;
	char	**paths;
	char	*str;
	int		i;

	line = find_path_line(envp);
	if (line == -1)
		return (NULL);
	paths = prepare_and_split(envp[line]);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		str = ft_join(paths[i], cmd);
		if (access(str, X_OK) == 0)
		{
			free_split(paths);
			return (str);
		}
		free(str);
		i++;
	}
	free_split(paths);
	return (NULL);
}

int	check_command(char *cmd, char **envp)
{
	char *path;

	path = find_path(cmd, envp);
	if (!path)
		return (0);
	if (access(path, X_OK) == 0)
	{
			free(path);
			return (1);
	}
	free(path);
	return (0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	printf("%s\n", find_path(argv[1], envp));
// 	// system("leaks a.out");
// 	return (0);
// }