CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
HPPS = ClapTrap.hpp FragTrap.hpp ScavTrap.hpp DiamondTrap.hpp
OBJS = $(SRCS:.cpp=.o)
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