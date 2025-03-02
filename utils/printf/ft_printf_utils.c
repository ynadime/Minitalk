/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynadime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:32:33 by ynadime           #+#    #+#             */
/*   Updated: 2024/11/18 16:32:36 by ynadime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		count += write(1, "-", 1);
		count += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int		count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_hexa(unsigned long int nb, char format)
{
	int		count;
	char	*str;

	count = 0;
	if (format == 'X')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (nb > 15)
	{
		count += ft_hexa(nb / 16, format);
		count += ft_putchar(str[nb % 16]);
	}
	else
		count += ft_putchar(str[nb]);
	return (count);
}
