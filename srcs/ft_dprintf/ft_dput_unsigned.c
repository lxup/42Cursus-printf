/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dput_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:08:29 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 02:30:05 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_dput_unsigned(unsigned int n)
{
	size_t	len;
	char	*nbr;

	if (n == 0)
		return (ft_put_char_to_fd('0', 2));
	nbr = ft_duitoa(n);
	len = ft_put_str_to_fd(nbr, 2);
	free(nbr);
	return (len);
}
