/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raviz-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:34:25 by raviz-es          #+#    #+#             */
/*   Updated: 2024/01/14 19:39:41 by raviz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
