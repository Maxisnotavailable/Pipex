/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:49:31 by molla             #+#    #+#             */
/*   Updated: 2022/11/22 07:14:21 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}
/*
#include <string.h>

int	main()
{
	const char	s[6] = "teste";
	int			c = 0;
	printf("%p ,  %s \n", s,s);
	printf("%p\n", ft_strchr(s, c));
	printf("%p\n", strchr(s, c));
	return (0);
}*/