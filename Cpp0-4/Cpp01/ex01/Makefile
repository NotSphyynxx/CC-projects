CPPC = c++

NAME = ZombieHorde

SRC = Zombie.cpp main.cpp ZombieHorde.cpp

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.opp)

HF = Zombie.hpp

all : $(NAME)

$(NAME) : $(OBJ) $(HF)
	$(CPPC) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.opp: %.cpp
	$(CPPC) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all