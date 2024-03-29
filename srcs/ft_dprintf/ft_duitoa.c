/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 01:46:22 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 01:46:24 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_duitoa(unsigned int n)
{
	char	*nbr;
	size_t	len;

	len = ft_nbr_len(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (n != 0)
	{
		nbr[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (nbr);
}
