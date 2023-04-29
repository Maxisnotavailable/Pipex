/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:22:06 by molla             #+#    #+#             */
/*   Updated: 2023/04/28 17:01:52 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_struct {
	char	**paths;
	char	**args;
	int		cmd_nbr;
	int		infile;
	int		outfile;
	int		pid;
	int		pid2;
}	t_struct;

void	child_process(int *fd, t_struct *pipex, char **argv, char **envp);
void	child2_process(int *fd, t_struct *pipex, char **argv, char **envp);
int		parent_process(int *fd, t_struct *pipex, int x);

void	free_paths(t_struct *pipex);
void	free_args(t_struct *pipex);
int		establishment(t_struct *pipex, char **argv, char **envp, int *fd);
void	create_paths_tab(t_struct *pipex, char **envp);
int		check_cmd(char **argv, t_struct *pipex, int i);

#endif