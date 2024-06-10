##
## @file_name: Makefile
## @directory: root
##
## @project_name: my_tokarray
## @author: Fohz67
##

PATH_SRC = ./src

SRC = $(PATH_SRC)/main.c \
	  $(PATH_SRC)/tokarray.c \

OBJ = $(SRC:.c=.o)

NAME = my_tokarray

CC = gcc

CFLAGS += -W -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: re

.PHONY: all clean fclean re
