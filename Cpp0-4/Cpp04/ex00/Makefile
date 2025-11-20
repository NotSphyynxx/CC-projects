CPPC = c++

NAME = Animal

SRC = Animal.cpp Dog.cpp Cat.cpp main.cpp WrongAnimal.cpp WrongCat.cpp WrongDog.cpp

HF = Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp WrongDog.hpp

CPP_FLAGS = #-std=c++98 -Wall -Wextra -Werror 

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