/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:33:31 by molla             #+#    #+#             */
/*   Updated: 2022/11/21 10:59:30 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	tot_size;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	tot_size = count * size;
	tab = malloc(tot_size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, tot_size);
	return (tab);
}
