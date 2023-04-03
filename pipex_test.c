/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:13:44 by molla             #+#    #+#             */
/*   Updated: 2023/03/31 18:03:46 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>*/

#include "Libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void	writestr(int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}

int main(void) 
{
    int     pid;
    int     pipefd[2];
    char    buf;
    int     i;
    int     fd;
    char    *s;
    char    *nb;
    
    i = 0;
    if (pipe(pipefd) == -1)
        return (1);
    pid = fork();
    if (pid == -1)
        exit(1);
    else if (pid == 0) // Child process
    {
        close(pipefd[1]);
        while (read(pipefd[0], &buf, 1) > 0)
            write(1, &buf, 1);
        writestr(1, "\n");
        close(pipefd[0]);
        exit(0);
    } 
    else  // Parent process
    {
        close(pipefd[0]);
        fd = open("file1", O_RDONLY);
        s = get_next_line(fd);
        free(s);
        while (s != NULL)
        {
            i++;
            s = get_next_line(fd);
            free(s);
        }
        nb = ft_itoa(i);
        writestr(pipefd[1], nb);
        free(nb);
        close(pipefd[1]);
        //wait(NULL);
    }
    if (close(fd) == -1)
        return (writestr(1, "close failed"), 1);
    //system("leaks pipex");
    return (0);
}