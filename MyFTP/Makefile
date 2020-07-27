##
## EPITECH PROJECT, 2020
## make
## File description:
## make
##

SRC =	$(wildcard src/*.c)

OBJ =   $(SRC:.c=.o)

NAME    =   myftp

$(NAME):    $(OBJ)
	gcc -I src/ -o $(NAME) $(OBJ)

all:    $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
