CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook

SRCS = Contact.cpp main.cpp PhoneBook.cpp Contact_helper.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) -c $^ $(CPPFLAGS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
