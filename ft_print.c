/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raviz-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:54:45 by raviz-es          #+#    #+#             */
/*   Updated: 2024/01/14 16:45:06 by raviz-es         ###   ########.fr       */
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

int	ft_print_d(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len += (int)write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		len += ft_print_d(n / 10);
	len += (int)write(1, &"0123456789"[n % 10], 1);
	return (len);
}

int	ft_print_p(unsigned	long int p)
{
	int		len;

	if (p == 0)
		return ((int)write(1, "(nil)", 5));
	len = 0;
	len += (int)write(1, "0x", 2);
	if (p > 15)
		len += ft_print_p(p / 16);
	len += (int)write(1, &"0123456789abcdef"[p % 16], 1);
	return (len);
}

int	ft_print_x(unsigned int x)
{
	int		len;

	len = 0;
	if (x > 15)
		len += ft_print_x(x / 16);
	len += (int)write(1, &"0123456789abcdef"[x % 16], 1);
	return (len);
}
