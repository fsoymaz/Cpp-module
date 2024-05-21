NAME = btc
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp BitcoinExchange.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

re: clean all

clean:
	rm -f $(NAME)

.PHONY: all clean re
