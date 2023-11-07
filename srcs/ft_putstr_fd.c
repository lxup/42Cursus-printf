/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:09:38 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/07 19:29:40 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (s && s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}