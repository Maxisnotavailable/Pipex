/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:47:33 by molla             #+#    #+#             */
/*   Updated: 2023/04/26 16:41:01 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_struct {
	char	**paths;
	char	**args;
	int		cmd_nbr;
	int		nb_cmd;
	int		outfile;
	int		pid;
	int		fd_in;
	int		fd_out;
	int		fd_pipe;
}	t_struct;

int	establishment(t_struct *pipex, int argc, char **argv, char **envp);
int	create_paths_tab(t_struct *pipex, char **envp);
int	check_cmd(char **argv, t_struct *pipex, int i);
int	cmd_needing(t_struct *pipex, int *fd, int argc);

#endif