##
## EPITECH PROJECT, 2023
## stumper
## File description:
## Makefile
##

NAME = mysh

SRC = 	src/main.c \
		src/utility_func.c \
		src/utility_func_2.c \
		src/utility_func_3.c \
		src/my_env.c \
		src/my_setenv.c \
		src/my_redirection.c \
		src/check_setenv.c \
		src/my_cd.c \
		src/path_mng.c \
		src/extended_cd.c \
		src/my_getnbr.c \
		src/my_unsetenv.c \
		src/my_exec.c \
		src/find_symbol.c \
		src/my_exit.c \
		src/my_str_to_word_array.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -W -pedantic -Wpadded -ggdb

CC = gcc

all:	$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

ban_function:
	nm ./$(NAME)

clean:
	find -type f -name "#*#" -delete -o \
	-type f -name "*~" -delete -o -type f -name "*.o" -delete -o \
	-type f -name "*.gc*" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all
