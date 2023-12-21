NAME = Phonebook
CC = g++
FLAGS =  -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp Contact.cpp Phonebook.cpp

OBJS = $(SRC:.cpp=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o Phonebook

clean :
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
re: clean fclean all