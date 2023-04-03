/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:11:59 by molla             #+#    #+#             */
/*   Updated: 2022/11/30 14:23:46 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_di(va_list args)
{
	int		i;
	int		nb;
	size_t	len;

	i = va_arg(args, int);
	nb = i;
	len = 0;
	if (i < 0)
	{
		len++;
		i *= -1;
	}
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	ft_putnbr_fd(nb, 1);
	if (nb == -2147483648)
		len = 11;
	if (nb == 0)
		return (1);
	return (len);
}
