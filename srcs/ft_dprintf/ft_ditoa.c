/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ditoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:09:15 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 01:37:32 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_digitlen(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_ditoa(int n)
{
	long	nbr;
	size_t	i;
	size_t	n_len;
	char	*str;

	nbr = (long)n;
	n_len = ft_digitlen(nbr);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (n == 0)
		str[i] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[(n_len - 1) - i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	str[n_len] = 0;
	return (str);
}
