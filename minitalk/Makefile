# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 16:38:36 by wwatik            #+#    #+#              #
#    Updated: 2023/03/23 16:38:39 by wwatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAME_S = server
NAME_BONUS = client_bonus
NAME_S_BONUS = server_bonus

SRC_C = client.c ft_atoi.c
SRC_S = server.c
SRC_C_BONUS = client_bonus.c ft_atoi.c
SRC_S_BONUS = server_bonus.c

CC = cc -Wall -Wextra -Werror

OBJS_C = ${SRC_C:%.c=%.o}
OBJS_S = ${SRC_S:%.c=%.o}
OBJS_C_BONUS = ${SRC_C_BONUS:%.c=%.o}
OBJS_S_BONUS = ${SRC_S_BONUS:%.c=%.o}

all : ft_printf $(NAME) $(NAME_S) 

ft_printf:
	make -C ./ft_printf

$(NAME) : $(OBJS_C)
	$(CC) $(OBJS_C) -o $(NAME)
$(NAME_S) : $(OBJS_S)
	$(CC) ./ft_printf/libftprintf.a $(OBJS_S) -o $(NAME_S)

bonus : ft_printf $(NAME_BONUS) $(NAME_S_BONUS)
$(NAME_BONUS) : $(OBJS_C_BONUS)
	$(CC) $(OBJS_C_BONUS) -o $(NAME_BONUS)
$(NAME_S_BONUS) : $(OBJS_S_BONUS)
	$(CC) ./ft_printf/libftprintf.a $(OBJS_S_BONUS) -o $(NAME_S_BONUS)

%.o : %.c minitalk.h minitalk_bonus.h
	$(CC) -c $< -o $@

clean :
	rm -f $(OBJS_C) $(OBJS_S) $(OBJS_C_BONUS) $(OBJS_S_BONUS) 
	make clean -C ./ft_printf

fclean : clean
	rm -f $(NAME) $(NAME_S) $(NAME_BONUS) $(NAME_S_BONUS)
	make fclean -C ./ft_printf

re : fclean all 

.PHONY : ft_printf all clean fclean re bonus
