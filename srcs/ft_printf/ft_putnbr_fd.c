/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:09:35 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 02:33:01 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nbr_len(unsigned int nbr)
{
	size_t	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

size_t	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	char	*nbr;

	nbr = ft_itoa(n);
	len = ft_put_str_to_fd(nbr, fd);
	free(nbr);
	return (len);
}
