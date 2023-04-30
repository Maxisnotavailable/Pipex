/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:00:57 by molla             #+#    #+#             */
/*   Updated: 2023/04/26 18:08:34 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_paths(t_struct *pipex)
{
	int	i;

	i = -1;
	while (pipex->paths[++i] != NULL)
	{
		free(pipex->paths[i]);
		pipex->paths[i] = NULL;
	}
	free(pipex->paths);
	pipex->paths = NULL;
}

void	free_args(t_struct *pipex)
{
	int	i;

	i = -1;
	while (pipex->args[++i] != NULL)
	{
		free(pipex->args[i]);
		pipex->args[i] = NULL;
	}
	free(pipex->args);
	pipex->args = NULL;
}

void	child_process(t_struct *pipex, char **argv, char **envp)
{
	if (pipex->fd_pipe != 0)
		close(pipex->fd_pipe);
	if (check_cmd(argv, pipex, -1) == 1)
	{
		free_args(pipex);
		free_paths(pipex);
		exit (1);
	}
	dup2(pipex->fd_out, STDOUT_FILENO);
	dup2(pipex->fd_in, STDIN_FILENO);
	execve(pipex->args[0], pipex->args, envp);
	perror("execve");
	exit (0);
}

void	parent_process(t_struct *pipex, int argc, int x)
{
	if (x == 0)
	{
		close(pipex->fd_in);
		close(pipex->fd_out);
		pipex->fd_in = pipex->fd_pipe;
		pipex->fd_pipe = 0;
	}
	else if (x == 1)
	{
		pipex->cmd_nbr = 1;
		while (pipex->cmd_nbr++ <= argc - 3)
			waitpid(pipex->pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int			fd[2];
	t_struct	pipex;

	if (establishment(&pipex, argc, argv, envp) == 1)
		return (1);
	while (pipex.cmd_nbr <= argc - 3)
	{
		if (cmd_needing(&pipex, fd, argc) == 1)
			return (1);
		if (pipex.pid == 0)
			child_process(&pipex, argv, envp);
		else
			parent_process(&pipex, argc, 0);
		pipex.cmd_nbr++;
	}
	parent_process(&pipex, argc, 1);
	free_paths(&pipex);
	unlink("Infile");
	return (0);
}
