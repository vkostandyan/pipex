/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:07:09 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/04 17:36:34 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void free_for_child(t_pipex pipex)
{
	free_split(pipex.cmd_args);
    free(pipex.cmd_path);
}

void free_for_parent(t_pipex pipex)
{
	close(pipex.infile);
	close(pipex.outfile);
	free_split(pipex.path_args);
}
