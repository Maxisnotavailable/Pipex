/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:09:37 by molla             #+#    #+#             */
/*   Updated: 2022/11/30 14:07:09 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_p(va_list args)
{
	unsigned long	i;
	unsigned long	nb;
	size_t			len;
	char			*hexa;

	i = va_arg(args, unsigned long);
	nb = i;
	len = 0;
	hexa = "0123456789abcdef";
	if (i == 0)
		i++;
	while (i > 0)
	{
		i /= 16;
		len++;
	}
	write (1, "0x", 2);
	ft_putbase_fd(nb, 1, hexa);
	return (len + 2);
}
