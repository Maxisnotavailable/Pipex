/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:00:57 by molla             #+#    #+#             */
/*   Updated: 2023/04/04 10:17:46 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

int parsing(int argc, char **argv)
{
	int fd;

	if (argc != 5)
		return (write(2, "Invalid numbers of arguments\n", 29), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("Open"), 1);
	if (close(fd) == -1)
		return (perror("Close"), 1);
	return (0);
}

int main(int argc, char **argv)
{
	int fd[2];
	int pid;
	
	if (parsing(argc, argv) == 1)
		return (1);
	if (pipe(fd) == -1)
		return (perror("Pipe"), 1);
	pid = fork();
	if (pid == -1)
		return (perror("Fork"), 1);
	
}