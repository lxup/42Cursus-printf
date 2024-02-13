/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:09:59 by lquehec           #+#    #+#             */
/*   Updated: 2024/02/13 02:30:05 by lquehec          ###   ########.fr       */
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
size_t	ft_put_char_to_fd(char c, int fd);
size_t	ft_put_str_to_fd(char *s, int fd);
size_t	ft_putnbr_fd(int n, int fd);
size_t	ft_nbr_len(unsigned int nbr);
size_t	ft_hex_len(unsigned int nbr);
size_t	ft_put_hex(unsigned int nbr, char format);
void	ft_put_hex_upper(unsigned int nbr);
void	ft_put_hex_lower(unsigned int nbr);
size_t	ft_put_unsigned(unsigned int n);

int		ft_dprintf(const char *str, ...);
char	*ft_ditoa(int n);
char	*ft_duitoa(unsigned int n);
size_t	ft_dput_uintptr(unsigned long long ptr);
size_t	ft_dnbr_len(unsigned int nbr);
size_t	ft_dhex_len(unsigned int nbr);
size_t	ft_dput_hex(unsigned int nbr, char format);
void	ft_dput_hex_upper(unsigned int nbr);
void	ft_dput_hex_lower(unsigned int nbr);
size_t	ft_dput_unsigned(unsigned int n);

#endif