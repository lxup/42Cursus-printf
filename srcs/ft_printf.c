/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:40:51 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/08 12:09:58 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list args, char c, size_t *str_len)
{
	if (c == 'c')
		*str_len += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		*str_len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		*str_len += ft_put_uintptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		*str_len += ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		*str_len += ft_put_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		*str_len += ft_put_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		*str_len += ft_putchar_fd('%', 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	str_len;

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

// int	main(void)
// {
// 	int	valuePrinted;
// 	// printf("*==========PRINTF==========*");
// 	// printf("String: %s\nInt: %d\n", "salam", 59);
// 	valuePrinted = 0;
// 	ft_printf("*==========FT_PRINTF START==========*\n");
// 	valuePrinted = ft_printf("String: %s\nInt: %d\nHexLow: %x\nHexUp: %X\n",
			// "salam", 59, 123456789, 123456789);
// 	ft_printf("*==========FT_PRINTF END==========*\n");
// 	printf("Value printed: %i", valuePrinted);
// 	return (0);
// }