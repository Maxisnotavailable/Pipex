/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:58:27 by molla             #+#    #+#             */
/*   Updated: 2023/02/03 09:52:33 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	nbstr;

	i = 0;
	nbstr = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			nbstr++;
		i++;
	}
	return (nbstr);
}

static char	**fill_arr(char const *s, char c, int nbstr, char **arr)
{
	int	start;
	int	len;
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			len = 0;
			while (s[i] && s[i++] != c)
				len++;
			i--;
			arr[nbstr] = ft_calloc(sizeof(char), (len + 1));
			if (!arr[nbstr])
				return (NULL);
			ft_strlcpy(arr[nbstr], &s[start], len + 1);
			nbstr++;
		}
		if (s[i] != '\0')
			i++;
	}
	arr[nbstr] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		nbstr;

	if (!s)
		return (NULL);
	if (s[0] == '\0' && c == '\0')
	{
		arr = (char **)malloc(sizeof(char *));
		arr[0] = NULL;
		return (arr);
	}
	while (*s == c)
		s++;
	nbstr = count_word(s, c);
	arr = (char **)malloc(sizeof(char *) * (nbstr + 1));
	if (!arr)
		return (NULL);
	return (fill_arr(s, c, 0, arr));
}
