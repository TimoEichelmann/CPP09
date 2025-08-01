NAME = Pmerge
SRC = main.cpp Pmerge.cpp
SRC_DIR = src
FULL_SRC= $(addprefix $(SRC_DIR)/, $(SRC) )

.PHONY: clean fclean all re
all : $(NAME)
$(NAME) : $(FULL_SRC)
		c++ -Wall -Werror -Wextra -g -std=c++98 -o $(NAME) $(FULL_SRC)
fclean :
	-rm $(NAME)
clean :
	-rm $(NAME)
re : fclean all