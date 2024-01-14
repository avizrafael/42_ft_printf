/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raviz-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:31:00 by raviz-es          #+#    #+#             */
/*   Updated: 2024/01/14 16:39:55 by raviz-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

int	ft_print_c(int c);
int	ft_print_s(char *s);
int	ft_print_d(int n);
int	ft_print_p(unsigned long int p);
int	ft_print_x(unsigned int x);
int	ft_check(const char *format, va_list ap);
int	ft_printf(const char *format, ...);

#endif