/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:46:00 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/08 12:14:43 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int n)
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
