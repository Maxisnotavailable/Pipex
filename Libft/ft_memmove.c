/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:20:29 by molla             #+#    #+#             */
/*   Updated: 2022/11/09 14:58:27 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*a;
	char	*b;

	i = 0;
	a = (void *)src;
	b = dst;
	if (!dst && !src)
		return (NULL);
	if (a < b)
	{
		while (len-- > 0)
			b[len] = a[len];
		return (dst);
	}
	while (i < len)
	{
		b[i] = a[i];
		i++;
	}
	return (dst);
}
