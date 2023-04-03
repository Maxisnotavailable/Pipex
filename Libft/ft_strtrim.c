/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:31:52 by molla             #+#    #+#             */
/*   Updated: 2023/02/21 20:09:41 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	find_istart(const char *s1, const char *set)
{
	size_t	istart;

	istart = 0;
	while (s1[istart])
	{
		if (is_set(s1[istart], set) == 0)
			return (istart);
		istart++;
	}
	return (istart);
}

static int	find_iend(const char *s1, const char *set)
{
	size_t	iend;

	iend = ft_strlen(s1) - 1;
	while (s1[iend] && iend > 0)
	{
		if (is_set(s1[iend], set) == 0)
			return (iend);
		iend--;
	}
	return (iend);
}

static char	*if_str_empty(char *str)
{
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char *s1, const char *set)
{
	size_t	i;
	size_t	istart;
	size_t	iend;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	istart = find_istart(s1, set);
	str = malloc(sizeof(char));
	if (istart >= ft_strlen(s1))
		return (if_str_empty(str));
	free(str);
	iend = find_iend(s1, set);
	i = 0;
	str = malloc(sizeof(char) * (iend - istart + 1 + 1));
	if (!str || iend < istart)
		return (NULL);
	while (i < iend - istart + 1)
	{
		str[i] = s1[istart + i];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
/*
int	main()
{
	char const s1[17] = "tripouille   xxx";
	char const set[3] = " x";
	ft_strtrim(s1, set);
	return (0);
}
*/
