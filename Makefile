PATH = ../ft_containers
INCLUDES = -I$(PATH)/containers -I$(PATH)/utils

CXX = clang++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 $(INCLUDES) $(ADDFLAGS)
NAME = ft_containers
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
