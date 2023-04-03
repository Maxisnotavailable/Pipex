/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:58:28 by molla             #+#    #+#             */
/*   Updated: 2022/11/13 19:23:48 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	p;
	char	*str;

	str = (char *)haystack;
	i = 0;
	if (!*needle || (len == 0 && needle == '\0'))
		return (str);
	if (len == 0)
		return (NULL);
	while (str[i] && i < len)
	{
		p = 0;
		if (needle[p] == str[i])
		{
			while (needle[p] == str[i + p] && i + p < len)
			{
				if (needle[++p] == '\0')
					return (str + i);
			}
		}
		i++;
	}
	return (NULL);
}
