/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:24:29 by molla             #+#    #+#             */
/*   Updated: 2022/11/18 16:46:45 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
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
	return (sdup);
}
/*
int main()
{
	char	*ds;
	ds = ft_strdup("salut");
	printf("%s\n", ds);
	printf("%s\n", strdup("salut"));
	free(ds);
	return(0);
}
*/
