NAME = convert

CC = c++

SRC = $(wildcard *.cpp)
FLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC)  -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean all