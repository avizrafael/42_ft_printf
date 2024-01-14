/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raviz-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:38:28 by raviz-es          #+#    #+#             */
/*   Updated: 2024/01/14 19:39:27 by raviz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
