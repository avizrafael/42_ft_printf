/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raviz-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:54:45 by raviz-es          #+#    #+#             */
/*   Updated: 2024/01/14 18:36:22 by raviz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int c)
{
	return ((int)write(1, &c, 1));
}

int	ft_print_s(char *s)
{
	int		len;

	len = 0;
	if (!s)
		return ((int)write(1, "(null)", 6));
	while (*s)
	{
		len += (int)write(1, s, 1);
		s++;
	}
	return (len);
}

int	ft_print_n(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return ((int)write(1, "-2147483648", 11));
	if (n < 0)
	{
		len += (int)write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		len += ft_print_n(n / 10);
	len += (int)write(1, &"0123456789"[n % 10], 1);
	return (len);
}

int	ft_print_u(unsigned int n)
{
	int		len;

	len = 0;
	if (n > 9)
		len += ft_print_u(n / 10);
	len += (int)write(1, &"0123456789"[n % 10], 1);
	return (len);
}

int	ft_print_p(unsigned	long int p)
{
	int		len;

	len = 0;
	if (p == 0)
		len += ((int)write(1, "(nil)", 5));
	else
	{
		
		if (p > 15)
			len += ft_print_p(p / 16);
		else
			len += (int)write(1, "0x", 2);
		len += (int)write(1, &"0123456789abcdef"[p % 16], 1);
	}
	return (len);
}

int	ft_print_x(unsigned int x, char c)
{
	int		len;

	len = 0;
	if (x > 15)
		len += ft_print_x(x / 16, c);
	if (c == 'X')
		len += (int)write(1, &"0123456789ABCDEF"[x % 16], 1);
	else
		len += (int)write(1, &"0123456789abcdef"[x % 16], 1);
	return (len);
}
