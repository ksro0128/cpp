CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ScalarConverter.cpp
HPPS = ScalarConverter.hpp
OBJS = $(SRCS:.cpp=.o)
NAME = convert

all : $(NAME)

$(NAME) : $(OBJS) $(HPPS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS) : $(SRCS)
	$(CPP) $(FLAGS) -c $^

clean :
	rm -rf $(OBJS)

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean