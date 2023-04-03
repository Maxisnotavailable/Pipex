/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:38:46 by molla             #+#    #+#             */
/*   Updated: 2022/11/11 08:30:21 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	if ((!dst || !src) && dstsize == 0)
		return (0);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0 || dstlen >= dstsize)
		return (srclen + dstsize);
	while (src[i] && i < dstsize - 1 - dstlen)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (srclen + dstlen);
}
/*
int	main()
{
	char	dst[100] = "bonjour";
	const char	src[100] = "salut";
	printf("%s\n", dst);
	printf("%zu\n", ft_strlcat(dst, src, 8));
	printf("%zu\n", strlcat(dst, src, 8));
	printf("%s\n", dst)
}
*/
