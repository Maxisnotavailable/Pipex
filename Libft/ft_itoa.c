/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:06:28 by molla             #+#    #+#             */
/*   Updated: 2022/11/14 10:33:07 by molla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_str(char *str, int n, int nbchar)
{
	if (n == -2147483648)
	{
		str[10] = '8';
		n /= 10;
		nbchar--;
	}
	if (n < 0)
		n *= -1;
	while (nbchar > 0)
	{
		str[nbchar-- - 1] = (n % 10) + 48;
		n /= 10;
	}
	if (str[0] == '0' && str [1] != '\0')
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		ctn;
	int		nbchar;
	char	*str;

	ctn = n;
	nbchar = 0;
	if (n <= 0)
		nbchar += 1;
	while (ctn != 0)
	{
		ctn /= 10;
		nbchar++;
	}
	str = malloc(sizeof(char) * (nbchar + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, nbchar + 1);
	fill_str(str, n, nbchar);
	return (str);
}

/*
int main()
{
	//ft_itoa(12345);
	//printf("%s\n", ft_itoa(12345));
	//printf("%s\n", ft_itoa(-12345));
	//printf("%s\n", ft_itoa(0));
	//printf("%s\n", ft_itoa(-1));
	//printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}
*/
