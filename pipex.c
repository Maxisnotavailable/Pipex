/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:00:57 by molla             #+#    #+#             */
/*   Updated: 2023/04/03 10:53:08 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int parsing(int argc, char **argv)
{
	int fd;

	if (argc != 5)
		return (write(2, "Incorrect number of arguments", 29), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "File does not exist\n", 20), 1);
	if (close(fd) == -1)
		return (write(2, "File can't be closed\n", 21), 1);
	return (0);
}

int main(int argc, char **argv)
{
	int fd[2];
	int pid;
	
	if (parsing(argc, argv) == 1)
		return (1);
	if (pipe(fd) == -1)
		return (write(2, "The pipe didn't open\n", 21), 1);
	pid = fork();
	if (pid == -1)
		return (write(2, "Error with the fork\n", 20), 1);
	
}