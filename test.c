/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:23:26 by vkostand          #+#    #+#             */
/*   Updated: 2024/05/03 17:24:07 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main()
{
	char *args[3];
 
	args[0] = "ls";
	args[1] = "-a";
	args[2] = NULL;
	execve("/bin/ls", args, NULL);
	printf("This line will not be executed.\n");
 
	return (0);
}