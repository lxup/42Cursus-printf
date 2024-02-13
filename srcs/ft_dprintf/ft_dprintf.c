/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:40:51 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 01:39:42 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format(va_list args, char c, size_t *str_len)
{
	if (c == 'c')
		*str_len += ft_putchar_fd(va_arg(args, int), 2);
	else if (c == 's')
		*str_len += ft_putstr_fd(va_arg(args, char *), 2);
	else if (c == 'p')
		*str_len += ft_dput_uintptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		*str_len += ft_putnbr_fd(va_arg(args, int), 2);
	else if (c == 'u')
		*str_len += ft_dput_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		*str_len += ft_dput_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		*str_len += ft_putchar_fd('%', 2);
}

int	ft_dprintf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	str_len;

	if (!str)
		return (-1);
	i = 0;
	str_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_format(args, str[i + 1], &str_len);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			str_len++;
		}
		i++;
	}
	va_end(args);
	return (str_len);
}
