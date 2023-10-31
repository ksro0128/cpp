CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = $(SRCS:.cpp=.o)
HPPS = Fixed.hpp Point.hpp
GCHS = $(HPPS:=.gch)
NAME = a.out

all : $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS) : $(SRCS) $(HPPS)
	$(CPP) $(FLAGS) -c $^

clean :
	rm -rf $(OBJS) $(GCHS)

fclean :
	make clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean