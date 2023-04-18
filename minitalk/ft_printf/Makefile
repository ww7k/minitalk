# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 22:03:18 by wwatik            #+#    #+#              #
#    Updated: 2022/11/28 22:03:23 by wwatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar rc
SRCS = ft_printf.c ft_putchar.c ft_putnbhex.c ft_putnbr.c ft_putnbuns.c ft_putptr.c ft_putstr.c
CC = cc -Wall -Wextra -Werror
OBJS = ${SRCS:%.c=%.o}

all : $(NAME)
$(NAME) : $(OBJS) 
%.o : %.c ft_printf.h
	$(CC) -c $<
	$(AR) $(NAME) $@
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean $(NAME)
.PHONY : all clean fclean re