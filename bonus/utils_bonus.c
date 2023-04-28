/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:34:04 by molla             #+#    #+#             */
/*   Updated: 2023/04/26 18:19:01 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	heredoc_create_fdin(t_struct *pipex, char **argv)
{
	char	*str;

	pipex->fd_in = open("Infile", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (pipex->fd_in == -1)
		return (perror("Infile"), 1);
	while (1)
	{
		write(1, "> ", 2);
		str = get_next_line(0);
		if (ft_strncmp(str, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(str);
			break ;
		}
		write(pipex->fd_in, str, ft_strlen(str));
		free(str);
	}
	close(pipex->fd_in);
	pipex->fd_in = open("Infile", O_RDONLY);
	if (pipex->fd_in == -1)
		return (perror("Infile"), 1);
	return (0);
}

int	establishment(t_struct *pipex, int argc, char **argv, char **envp)
{
	if (create_paths_tab(pipex, envp) == 1)
		return (1);
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		pipex->cmd_nbr = 2;
		if (heredoc_create_fdin(pipex, argv) == 1)
			return (1);
		pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT
				| O_APPEND, S_IRWXU);
		if (pipex->outfile == -1)
			return (perror("Outfile"), 1);
		return (0);
	}
	else
	{
		pipex->cmd_nbr = 1;
				pipex->fd_in = open(argv[1], O_RDONLY, S_IRWXU);
		if (pipex->fd_in == -1)
			return (perror("Infile"), 1);
		pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT
				| O_TRUNC, S_IRWXU);
		if (pipex->outfile == -1)
			return (perror("Outfile"), 1);
	}
	return (0);
}

int	create_paths_tab(t_struct *pipex, char **envp)
{
	int	i;

	while (ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	pipex->paths = ft_split(ft_strchr(*envp, '/'), ':');
	i = -1;
	while (pipex->paths[++i] != NULL)
		pipex->paths[i] = ft_strjoin_gnl(pipex->paths[i], "/", 0);
	return (0);
}

int	check_cmd(char **argv, t_struct *pipex, int i)
{
	char	*full_path;

	pipex->args = ft_split(argv[pipex->cmd_nbr + 1], ' ');
	while (pipex->paths[++i] != NULL)
	{
		full_path = ft_strjoin(pipex->paths[i], pipex->args[0], 0);
		if (access(full_path, X_OK) == 0)
		{
			free(full_path);
			break ;
		}
		free(full_path);
	}
	if (pipex->paths[i] == NULL)
	{
		ft_printf("command not found: %s\n", pipex->args[0]);
		return (1);
	}
	if (pipex->paths[i] != NULL)
		pipex->args[0] = ft_strjoin(pipex->paths[i], pipex->args[0], 1);
	return (0);
}

int	cmd_needing(t_struct *pipex, int *fd, int argc)
{
	if (pipex->cmd_nbr != argc - 3)
	{
		if (pipe(fd) == -1)
			return (perror("Pipe"), 1);
		pipex->fd_out = fd[1];
		pipex->fd_pipe = fd[0];
	}
	else
		pipex->fd_out = pipex->outfile;
	pipex->pid = fork();
	if (pipex->pid == -1)
		return (perror("Fork"), 1);
	return (0);
}
