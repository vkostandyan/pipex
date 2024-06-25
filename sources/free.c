/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:29:09 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/25 18:16:20 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **str)
{
	while (*str)
	{
		free(*str);
		str++;
	}
	free(str);
}

void	free_main(t_pipex pipex)
{
	printf("hastat stex\n");
	free(pipex.paths);
	free_split(pipex.path_args);
}

void	free_cmd(t_pipex pipex)
{
	free_split(pipex.path_args);
	free(pipex.cmd_path);
}
