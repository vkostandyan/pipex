/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:29:09 by vkostand          #+#    #+#             */
/*   Updated: 2024/06/28 15:20:01 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str[i]);
	str[i] = NULL;
	free(str);
	str = NULL;
}

void	free_main(t_pipex *pipex)
{
	int	c1;
	int	c2;

	c1 = close(pipex->infile);
	c2 = close(pipex->outfile);
	if (c2 != 0 || c1 != 0)
		send_error(CLOSE_ERR);
	free_split(pipex->path_args);
}
