# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 19:16:33 by ilarhrib          #+#    #+#              #
#    Updated: 2024/11/23 19:16:36 by ilarhrib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
NAME = libftprintf.a
HF = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
LCC = ar rcs
SRCS = ft_printf.c ft_printf_hex.c ft_printf_utils.c
OBJF = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJF)

%.o : %.c $(HF)
	$(CC) $(CFLAGS) -c $< -o $@
	$(LCC) $(NAME) $@

clean :
	rm -f $(OBJF)

fclean : clean
	rm -f $(NAME)

re : fclean $(name)

.PHONY : clean