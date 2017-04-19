NAME = Rubik

HDIR = ./includes/
SDIR = ./sources/
ODIR = ./objects/

SRC = main.cpp\
	  Parser.cpp\

OBJ = $(SRC:.cpp=.o)

DIR_S = $(addprefix $(SDIR), $(SRC))
DIR_O = $(addprefix $(ODIR), $(OBJ))

INCLUDE = -I $(HDIR)

CC = clang++
#CFLAGS = -std=c++11 -Wall -Werror -Wextra -g
CFLAGS = -std=c++11 -g

RED= \033[31m
CYAN= \033[36m
GREY= \033[90m
NORMA= \033[00m
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(ODIR) $(DIR_O)
	@$(CC) $(DIR_O) -o $(NAME);
	@echo "$(CYAN)[$(NAME)]$(GREY) Executable created.$(NORMAL)";

$(ODIR):
	@mkdir -p $(ODIR);

$(ODIR)%.o: $(SDIR)%.cpp
	@echo "$(CYAN)[$(NAME)]$(GREY) Compiling $<.$(NORMAL)";
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@;

clean:
	@rm -f $(DIR_O);
	@rm -rf $(ODIR);
	@echo "$(CYAN)[$(NAME)]$(RED) All objects file deleted.$(NORMAL)";

fclean: clean
	@rm -f $(NAME);
	@echo "$(CYAN)[$(NAME)]$(RED) Executable deleted.$(NORMAL)";

re: fclean all	
