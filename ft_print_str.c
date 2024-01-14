/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raviz-es <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:54:45 by raviz-es          #+#    #+#             */
/*   Updated: 2024/01/14 19:39:25 by raviz-es         ###   ########.fr       */
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
