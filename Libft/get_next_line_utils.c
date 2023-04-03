/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:47:06 by molla             #+#    #+#             */
/*   Updated: 2023/02/09 13:39:22 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *s, int x)
{
	char	*sdup;
	int		i;

	i = 0;
	sdup = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!sdup)
		return (NULL);
	while (s[i])
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	if (x == 1)
		free(s);
	return (sdup);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ssub;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s) || len == 0)
	{
		ssub = malloc(sizeof(char));
		*ssub = '\0';
		if (!ssub)
			return (NULL);
		return (ssub);
	}
	if (len + 1 <= ft_strlen(s))
		ssub = malloc(sizeof(char) * (len + 1));
	else
		ssub = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!ssub)
		return (NULL);
	i = -1;
	while (len-- && s[++i])
		ssub[i] = s[start + i];
	ssub[i + 1] = '\0';
	return (ssub);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int x)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[i - lens1])
	{
		str[i] = s2[i - lens1];
		i++;
	}
	str[i] = '\0';
	free(s1);
	if (x == 1)
		free(s2);
	return (str);
}
