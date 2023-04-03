/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 07:25:49 by molla             #+#    #+#             */
/*   Updated: 2022/11/30 18:01:50 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
size_t	ft_printf_cspercent(va_list args, const char *format);
size_t	ft_printf_p(va_list args);
size_t	ft_printf_di(va_list args);
size_t	ft_printf_u(va_list args);
size_t	ft_printf_xx(va_list args, const char *format);
size_t	ft_print(const char *format);
void	ft_putbase_fd(unsigned long n, int fd, char *base);

#endif