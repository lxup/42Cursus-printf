# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 19:15:54 by lquehec           #+#    #+#              #
#    Updated: 2023/11/15 15:33:39 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
			ft_itoa.c \
			ft_uitoa.c \
			ft_put_hex.c \
			ft_put_unsigned.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_put_uintptr.c \

SRCS_DIR = ./srcs/

SRCS =		$(addprefix $(SRCS_DIR), $(SRC))

OBJS		= ${SRCS:.c=.o}

CC			= cc
RM			= rm -f
AR			= ar rc
RN			= ranlib
HEADER_DIR	= ./includes/

CFLAGS 		= -Wall -Wextra -Werror

NAME		= libftprintf.a

.c.o:
			${CC} ${CFLAGS} -I ${HEADER_DIR} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
