# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 22:27:57 by ilarhrib          #+#    #+#              #
#    Updated: 2025/02/12 14:29:00 by ilarhrib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

#BS_NAME    = so_long_bonus

HF = "includes/so_long.h"

CC        = cc

CFLAGS    = -Wall -Werror -Wextra

SRCS    = src/ft_printf.c src/ft_printf_hex.c src/ft_printf_utils.c src/map_check.c src/utils_1.c src/utils_2.c src/path_check.c src/map_check_2.0.c src/utils_3.c src/get_next_line.c src/get_next_line_utils.c textures/ft_window.c textures/ft_window_2.0.c textures/ft_window_3.0.c textures/ft_window_4.0.c src/utils_4.c

#BS_SRCS    = 

OBJS    = $(SRCS:.c=.o)

#BS_OBJS    = $(BS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#@bonus: $(BS_NAME)

#$(BS_NAME): $(BS_OBJS)
#	$(CC) $(CFLAGS) $(BS_OBJS) -lmlx -framework OpenGL -framework AppKit -o $(BS_NAME)

%.o: %.c $(HF)
	$(CC) $(CFLAGS)  -Imlx -c $< -o $@

#%.o: %.c so_long_bonus.h
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BS_OBJS)

fclean: clean
	rm -f $(NAME) $(BS_NAME)

re: fclean all