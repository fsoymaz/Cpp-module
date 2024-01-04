NAME = Brain
CC = g++
FLAGS =  -Wall -Wextra -Werror -std=c++98 -g

Src = $(wildcard *.cpp)

OBJS = $(Src:.cpp=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
re: clean fclean all