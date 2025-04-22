# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 16:14:42 by ilarhrib          #+#    #+#              #
#    Updated: 2025/03/06 17:14:35 by ilarhrib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAMEB = checker

HFM = includes/push_swap.h

HFB = bonus/push_swap_bonus.h

CC        = cc

CFLAGS    = -Wall -Werror -Wextra

SRCS    = src/ft_printf.c src/ft_printf_hex.c src/ft_printf_utils.c src/push.c \
		src/swap.c src/rotate.c src/reverse_rotate.c src/push_swap.c src/utils_1.c src/utils_2.c src/utils_3.c \
		src/utils_4.c src/utils_5.c src/utils_6.c src/best_move.c src/costs_calc.c src/positions.c src/sort.c

SRCSB = bonus/checker_bonus.c bonus/ft_atoi_bonus.c bonus/ft_fill_bonus.c bonus/ft_list_bonus.c bonus/ft_parsing_utils_bonus.c \
		bonus/ft_parsing_bonus.c bonus/ft_push_bonus.c bonus/ft_reverse_rotate_bonus.c bonus/ft_rotate_bonus.c bonus/ft_split_bonus.c \
		bonus/ft_stack_bonus.c bonus/ft_swap_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/push_swap_utils_bonus.c

OBJS = $(SRCS:.c=.o)

OBJ_B = $(SRCSB:.c=.o)

all : $(NAME)

bonus : $(NAMEB)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAMEB): $(OBJ_B)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HFM)
	$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(HFB)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all clean bonus re