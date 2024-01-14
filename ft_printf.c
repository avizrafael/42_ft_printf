/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raviz-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:30:41 by raviz-es          #+#    #+#             */
/*   Updated: 2024/01/14 16:50:39 by raviz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char *format, va_list ap)
{
	int		len;

	len = 0;
	if (*format == 'c')
		len = ft_print_c(va_arg(ap, int));
	else if (*format == 's')
		len = ft_print_s(va_arg(ap, char *));
	else if (*format == 'd' || *format == 'i')
		len = ft_print_d(va_arg(ap, int));
	else if (*format == 'p')
		len = ft_print_p(va_arg(ap, unsigned long int));
	else if (*format == 'x' || *format == 'X')
		len = ft_print_x(va_arg(ap, unsigned int));
	else if (*format == '%')
		len = (int)write(1, "%", 1);
	else
		len = (int)write(1, format, 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			len += ft_check(++format, ap);
		}
		else
		{
			len += (int)write(1, format, 1);
		}
		format++;
	}
	va_end(ap);
	return (len);
}
