/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:09:59 by lquehec           #+#    #+#             */
/*   Updated: 2023/11/15 16:48:51 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
size_t	ft_put_uintptr(unsigned long long ptr);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_putnbr_fd(int n, int fd);
size_t	ft_nbr_len(unsigned int nbr);
size_t	ft_hex_len(unsigned int nbr);
size_t	ft_put_hex(unsigned int nbr, char format);
void	ft_put_hex_upper(unsigned int nbr);
void	ft_put_hex_lower(unsigned int nbr);
size_t	ft_put_unsigned(unsigned int n);

#endif