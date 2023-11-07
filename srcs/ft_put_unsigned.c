/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:08:29 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/07 19:45:37 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


size_t  ft_put_unsigned(unsigned int n)
{
    size_t  len;
    char    *nbr;

    if (n == 0)
        return (ft_putchar_fd('0', 1));
    nbr = ft_uitoa(n);
    len = ft_putstr_fd(nbr, 1);
    free(nbr);
    return (len);
}