/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raviz-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:30:41 by raviz-es          #+#    #+#             */
/*   Updated: 2024/01/07 17:08:20 by raviz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_c(int c)
{
	return ((int)write(1, &c, 1));
}

int	ft_print_s(char *s)
{
	int		len;

	len = 0;
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

int ft_print_p(U_LI p)
{
	int		len;

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

int	ft_check(const char *format, va_list ap)
{
	int		len;

	len = 0;
	while (*format)
	{
		if (*format == 'c')
			len += ft_print_c(va_arg(ap, int));
		else if (*format == 's')
			len += ft_print_s(va_arg(ap, char *));
		else if (*format == 'd' || *format == 'i')
			len += ft_print_d(va_arg(ap, int));
		else if (*format == 'p')
			len += ft_print_p(va_arg(ap, U_LI));
		else if (*format == 'x' || *format == 'X')
			len += ft_print_x(va_arg(ap, unsigned int));
		else if (*format == '%')
			len += (int)write(1, "%", 1);
		else
			len += (int)write(1, format, 1);
		format++;
	}
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
			len += (int)write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (len);
}

int	main(void)
{
	char		byte;
	char		*string;
	int			number1;
	int			number2;
	void		*pointer;
	unsigned int	number3;
	unsigned int	number4;

	byte = 'a';
	string = "Hello World!";
	number1 = 42;
	number2 = -42;
	pointer = &number1;
	number3 = 42;
	number4 = 42;
	ft_printf("%c\n", byte);
	ft_printf("%s\n", string);
	ft_printf("%d\n", number1);
	ft_printf("%i\n", number2);
	//ft_printf("%d %i\n", number1, number2);
	ft_printf("%p\n", pointer);
	ft_printf("%x\n", number3);
	ft_printf("%X\n", number4);
	//ft_printf("%x %X\n", number3, number4);
	ft_printf("%%\n");
	ft_printf("%s %d\n", string, number1);
	return (0);
}