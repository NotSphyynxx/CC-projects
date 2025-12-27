NAME = Identify

CC = c++

RM = rm -rf

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp Base.cpp A.cpp B.cpp C.cpp

INCLUDES = Base.hpp A.hpp B.hpp C.hpp

OBJ = $(SOURCES:.cpp=.opp)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $@

%.opp: %.cpp $(INCLUDES)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)	

fclean: clean
	$(RM) $(NAME)

re: fclean all