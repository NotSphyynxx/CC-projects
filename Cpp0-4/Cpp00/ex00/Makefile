CPPC = c++

NAME = megaphone

SRC = megaphone.cpp

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.opp)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPPC) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.opp: %.cpp
	$(CPPC) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all