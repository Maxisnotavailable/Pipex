/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:30:11 by molla             #+#    #+#             */
/*   Updated: 2022/11/17 10:22:29 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ssub;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s) || len == 0)
	{
		ssub = ft_calloc(1, 1);
		return (ssub);
	}
	if (len + 1 <= ft_strlen(s))
		ssub = malloc(sizeof(char) * (len + 1));
	else
		ssub = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!ssub)
		return (NULL);
	while (len-- && s[i])
	{
		ssub[i] = s[start + i];
		i++;
	}
	ssub[i] = '\0';
	return (ssub);
}
/*
int	main()
{
	//char const s[36] = "i just want this part #############";	
	char const s[11] = "tripouille";
	//ft_substr(s, 0, 42000);
	printf("%s\n", ft_substr(s, 0, 42000));
	return (0);
}
*/
