# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 19:15:54 by lquehec           #+#    #+#              #
#    Updated: 2024/02/13 01:43:25 by lquehec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                     VARS                                     #
# **************************************************************************** #

END				=	\033[0m

# COLORS
BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m

# FONTS
BOLD			=	\033[1m
DIM				=	\033[2m
UNDERLINED		=	\033[4m
BLINK			=	\033[5m
REVERSE			=	\033[7m

# OS
OS				=	$(shell uname)

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #

NAME			=	libftprintf.a

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

CC				=	cc
RM				=	rm -rf
AR				=	ar rc
RN				=	ranlib
CFLAGS			+=	-Wall -Wextra -Werror -g3

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #

SRC_PATH		=	srcs
FT_PRINTF_PATH	=	ft_printf
FT_DPRINTF_PATH	=	ft_dprintf
INC_PATH		=	includes

# **************************************************************************** #
#                                    FLAGS                                     #
# **************************************************************************** #

CFLAGS		+=	-I$(INC_PATH)

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRC_FT_PRINTF = ft_printf \
			ft_itoa \
			ft_uitoa \
			ft_put_hex \
			ft_put_unsigned \
			ft_putchar_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_put_uintptr

SRC_FT_DPRINTF	=	ft_dprintf \
					ft_ditoa \
					ft_duitoa \
					ft_dput_hex \
					ft_dput_unsigned \
					ft_dput_uintptr

SRCS		=	$(addprefix $(SRC_PATH)/$(FT_PRINTF_PATH)/, $(addsuffix .c, $(SRC_FT_PRINTF))) \
			$(addprefix $(SRC_PATH)/$(FT_DPRINTF_PATH)/, $(addsuffix .c, $(SRC_FT_DPRINTF)))
# $(addsufix .c, $(SRC_FT_DPRINTF))

OBJS		= ${SRCS:.c=.o}

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all:		$(NAME)

.c.o:
			@printf "$(BLUE)> Compiling printf objects... %-33.33s\r$(END)" $@
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@${RN} ${NAME}
			@printf "\n$(GREEN)> $(NAME) was successfully compiled 🎉$(END)\n"
	
clean:
			@printf "$(YELLOW)> Cleaning printf... 🧹$(END)\n"
			@${RM} ${OBJS}

fclean:		clean
			@${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
