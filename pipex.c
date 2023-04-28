/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:50:57 by molla             #+#    #+#             */
/*   Updated: 2023/04/28 17:07:14 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, t_struct *pipex, char **argv, char **envp)
{
	close(fd[0]);
	if (check_cmd(argv, pipex, -1) == 1)
	{
		close(fd[1]);
		close(pipex->infile);
		system("leaks pipex");
		exit (1);
	}
	dup2(pipex->infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	execve(pipex->args[0], pipex->args, envp);
	close(fd[1]);
	close(pipex->infile);
	perror("execve");
	exit (1);
}

void	child2_process(int *fd, t_struct *pipex, char **argv, char **envp)
{
	pipex->cmd_nbr++;
	dup2(fd[0], STDIN_FILENO);
	if (check_cmd(argv, pipex, -1) == 1)
	{
		close(pipex->outfile);
		close(fd[0]);
		exit (1);
	}
	dup2(pipex->outfile, STDOUT_FILENO);
	execve(pipex->args[0], pipex->args, envp);
	close(pipex->outfile);
	close(fd[0]);
	perror("execve");
	exit (1);
}

int	parent_process(int *fd, t_struct *pipex, int x)
{
	if (x == 0)
	{
		close(pipex->infile);
		close(fd[1]);
		pipex->pid2 = fork();
		if (pipex->pid2 == -1)
			return (perror("Fork"), 1);
	}
	else if (x == 1)
	{
		close(fd[0]);
		close(pipex->outfile);
		waitpid(pipex->pid, NULL, 0);
		waitpid(pipex->pid2, NULL, 0);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int			fd[2];
	t_struct	pipex;

	if (argc != 5)
		return (write(2, "Invalid numbers of arguments\n", 29), 1);
	else
	{
		if (establishment(&pipex, argv, envp, fd) == 1)
			return (1);
		if (pipex.pid == 0)
			child_process(fd, &pipex, argv, envp);
		else
		{
			if (parent_process(fd, &pipex, 0) == 1)
				return (1);
			if (pipex.pid2 == 0)
				child2_process(fd, &pipex, argv, envp);
		}
	}
	parent_process(fd, &pipex, 1);
	//free_tab(pipex.paths);
	//free_tab(pipex.args);
	return (0);
}
