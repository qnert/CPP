CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow
NAME = diamondtrap

SRCS = ClapTrap.cpp FragTrap.cpp DiamondTrap.cpp ScavTrap.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
