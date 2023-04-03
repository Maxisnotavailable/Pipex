/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:22:09 by molla             #+#    #+#             */
/*   Updated: 2022/11/30 17:59:13 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	args;

	if (!fmt)
		return (0);
	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && (fmt[1] == 'c' || fmt[1] == 's' || fmt[1] == '%'))
			len += ft_printf_cspercent(args, fmt);
		else if (*fmt == '%' && fmt[1] == 'p')
			len += ft_printf_p(args);
		else if (*fmt == '%' && (fmt[1] == 'd' || fmt[1] == 'i'))
			len += ft_printf_di(args);
		else if (*fmt == '%' && fmt[1] == 'u')
			len += ft_printf_u(args);
		else if (*fmt == '%' && (fmt[1] == 'x' || fmt[1] == 'X'))
			len += ft_printf_xx(args, fmt);
		else
			len += ft_print(fmt--);
		(fmt) += 2;
	}
	va_end(args);
	return (len);
}
/*
int main()
{
	//int		d = -2147483648;
    //void    *p = -1;
    //char	s[100] = "bonjour";
    //char	c = '0';
    //ft_printf("sa%cut, %s, adresse Hello : %p, nb decimal
		 : %d, unsigned : %u\n", c, s, p, d, u);
    //printf("sa%cut, %s, adresse Hello : %p, nb decimal
		 : %d, unsigned : %u\n", c, s, p, d, u);
	ft_printf(" %x\n", -2147483648);
	printf(" %x\n", -2147483648);
    return(0);
}*/