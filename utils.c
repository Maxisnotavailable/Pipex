/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:34:53 by molla             #+#    #+#             */
/*   Updated: 2023/04/28 17:01:14 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}

int	establishment(t_struct *pipex, char **argv, char **envp, int *fd)
{
	pipex->cmd_nbr = 1;
	pipex->infile = open(argv[1], O_RDONLY, 0777);
	if (pipex->infile == -1)
		return (perror(argv[1]), 1);
	pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->outfile == -1)
		return (perror("Outfile"), 1);
	create_paths_tab(pipex, envp);
	if (pipe(fd) == -1)
		return (perror("Pipe"), 1);
	pipex->pid = fork();
	if (pipex->pid == -1)
		return (perror("Fork"), 1);
	return (0);
}

void	create_paths_tab(t_struct *pipex, char **envp)
{
	int	i;

	while (ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	pipex->paths = ft_split(ft_strchr(*envp, '/'), ':');
	i = -1;
	while (pipex->paths[++i] != NULL)
		pipex->paths[i] = ft_strjoin_gnl(pipex->paths[i], "/", 0);
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
