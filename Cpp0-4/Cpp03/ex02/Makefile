CPPC = c++

NAME = ClapTrap

SRC = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp

HF = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

CPP_FLAGS = -std=c++98 -Wall -Wextra -Werror 

OBJ = $(SRC:.cpp=.opp)

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