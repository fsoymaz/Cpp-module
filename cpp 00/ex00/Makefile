NAME = megaphone
CC = g++
FLAGS =  -Wall -Wextra -Werror -std=c++98

Src = Megaphone.cpp

OBJS = $(Src:.cpp=.o)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o megaphone

clean :
	$(RM) $(OBJS)

fclean: clean
		$(RM) megaphone
re: clean fclean all