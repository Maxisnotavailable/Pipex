/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:04:39 by molla             #+#    #+#             */
/*   Updated: 2022/11/30 14:25:56 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase_fd(unsigned long n, int fd, char *base)
{
	unsigned long	len_base;

	len_base = ft_strlen(base);
	if (n > len_base - 1)
	{
		ft_putbase_fd(n / len_base, fd, base);
		ft_putchar_fd(base[n % len_base], fd);
	}
	else
		ft_putchar_fd(base[n], fd);
}

size_t	ft_printf_xx(va_list args, const char *format)
{
	unsigned int	i;
	unsigned int	nb;
	size_t			len;
	char			*hexa;

	if (format[1] == 'x')
		hexa = "0123456789abcdef";
	else if (format[1] == 'X')
		hexa = "0123456789ABCDEF";
	i = va_arg(args, unsigned int);
	nb = i;
	len = 0;
	if (i == 0)
		i++;
	while (i > 0)
	{
		i /= 16;
		len++;
	}
	ft_putbase_fd(nb, 1, hexa);
	return (len);
}
