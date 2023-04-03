/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:48:02 by molla             #+#    #+#             */
/*   Updated: 2023/02/09 15:12:12 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_and_return_null(char **hold, char **str)
{
	if (!(*str))
		return (NULL);
	else
	{
		free(*hold);
		*hold = NULL;
		free(*str);
		*str = NULL;
		return (NULL);
	}
}

char	*ret_in_hold(char *str, char *hold, char *buf, int x)
{
	int		j;
	char	*ptr;

	j = 0;
	while (hold[j] != '\n')
		j++;
	if (x == 1)
	{
		str = ft_strjoin_gnl(ft_substr_gnl(hold, 0, j + 1), str, 1);
		return (str);
	}
	ptr = hold;
	hold = ft_strjoin_gnl(ft_strdup_gnl(ft_strchr(hold, '\n') + 1, 0), buf, 0);
	free(ptr);
	return (hold);
}

void	no_ret_in_buf(char **hold, char **str, char *buf)
{
	if (!(*hold))
		*str = ft_strjoin_gnl(*str, buf, 0);
	else
	{
		if (!ft_strchr(*hold, '\n'))
		{
			if ((*str[0]) == '\0')
				free(*str);
			*str = ft_strjoin_gnl(*hold, buf, 0);
			*hold = NULL;
		}
		else
		{
			*str = ret_in_hold(*str, *hold, buf, 1);
			*hold = ret_in_hold(*str, *hold, buf, 0);
		}
	}
}

void	ret_in_buf(char **hold, char **str, char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	if (!(*hold))
	{
		*str = ft_strjoin_gnl(*str, ft_substr_gnl(buf, 0, i + 1), 1);
		*hold = ft_strdup_gnl(ft_strchr(buf, '\n') + 1, 0);
	}
	else
	{
		if (!ft_strchr(*hold, '\n'))
		{
			*str = ft_strjoin_gnl(*hold, ft_strjoin_gnl(*str, \
				ft_substr_gnl(buf, 0, i + 1), 1), 1);
			*hold = ft_strdup_gnl(ft_strchr(buf, '\n') + 1, 0);
		}
		else
		{
			*str = ret_in_hold(*str, *hold, buf, 1);
			*hold = ret_in_hold(*str, *hold, buf, 0);
		}
	}
}

char	*get_next_line(int fd)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	char		*str;
	static char	*hold;

	str = malloc(sizeof(char));
	if (!str || fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free_and_return_null(&hold, &str));
	*str = '\0';
	*buf = '\0';
	ret = 1;
	while ((ret != 0 && (!ft_strchr(buf, '\n')) && (!ft_strchr(str, '\n'))))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		if (ret == 0 && str[0] == '\0' && hold == NULL)
			return (free_and_return_null(&hold, &str));
		if (!ft_strchr(buf, '\n'))
			no_ret_in_buf(&hold, &str, buf);
		else
			ret_in_buf(&hold, &str, buf);
	}
	if (*str == '\0')
		return (free_and_return_null(&hold, &str));
	return (str);
}
