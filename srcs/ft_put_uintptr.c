/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uintptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:44:47 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/08 12:16:47 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_uintptr_len(unsigned long long nbr)
{
	size_t	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

void	ft_put_uintptr_hex(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_put_uintptr_hex(nbr / 16);
		ft_put_uintptr_hex(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd(nbr - 10 + 'a', 1);
	}
}

size_t	ft_put_uintptr(unsigned long long ptr)
{
	size_t	len;

	if (ptr == 0)
		return (ft_putstr_fd("(nil)", 1));
	len = ft_putstr_fd("0x", 1);
	ft_put_uintptr_hex(ptr);
	len += ft_uintptr_len(ptr);
	return (len);
}
