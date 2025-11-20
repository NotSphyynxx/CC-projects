CPPC = c++

NAME = Animal

SRC = Animal.cpp Dog.cpp Cat.cpp Brain.cpp main.cpp WrongAnimal.cpp WrongCat.cpp

HF = Animal.hpp Dog.hpp Cat.hpp Brain.hpp WrongAnimal.hpp WrongCat.hpp

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