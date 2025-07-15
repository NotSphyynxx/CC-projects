# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 22:44:55 by ilarhrib          #+#    #+#              #
#    Updated: 2025/07/15 23:35:05 by ilarhrib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = philo
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRCS    = philo.c philo_utils/ft_atoi.c philo_utils/is_numeric.c parsing.c philo_utils/utils.c \
		philo_exe.c
		

OBJS    = $(SRCS:.c=.o)

HEADER = philo.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all