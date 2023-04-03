/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:45:35 by molla             #+#    #+#             */
/*   Updated: 2022/11/30 08:59:03 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_unsigned_fd(unsigned int n, unsigned int fd)
{
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_unsigned_fd(n / 10, fd);
		ft_putnbr_unsigned_fd(n % 10, fd);
	}
}

size_t	ft_printf_u(va_list args)
{
	unsigned int	i;
	unsigned int	nb;
	size_t			len;

	i = va_arg(args, int);
	nb = i;
	len = 0;
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	ft_putnbr_unsigned_fd(nb, 1);
	if (nb == 0)
		return (1);
	return (len);
}
