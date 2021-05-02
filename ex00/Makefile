NAME = convert

SRC = main.cpp CharLiteral.cpp IntLiteral.cpp FloatLiteral.cpp DoubleLiteral.cpp

OBJ = $(SRC:.cpp=.o)

H = ILiteral.hpp CharLiteral.hpp IntLiteral.hpp FloatLiteral.hpp DoubleLiteral.hpp

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(OBJ) -o $(NAME)

%.o: %.cpp $(H)
	clang++ -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all