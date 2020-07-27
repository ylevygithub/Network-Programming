##
## EPITECH PROJECT, 2020
## myteams
## File description:
## Makefile
##

NAME_SERVEUR	=	myteams_server
NAME_CLIENT		=	myteams_cli

SRC_SERVEUR		=	server/create_socket.c \
					server/error.c \
					server/helper.c \
					server/main.c \
					server/server_creation.c \
					server/server_loop.c \
					server/initialising_clients.c \
					server/incoming_connection.c \
					server/IO_operations.c \
					server/add_client_sock_to_array.c

SRC_CLIENT		=	client/main.c

OBJ_SERVEUR		=	$(SRC_SERVEUR:.c=.o)
OBJ_CLIENT		=	$(SRC_CLIENT:.c=.o)

CFLAGS			=	-W -Wall -Wextra -g

RM				=	rm -rf

all:
	gcc -o $(NAME_SERVEUR) $(CFLAGS) $(SRC_SERVEUR)
	gcc -o $(NAME_CLIENT) $(CFLAGS) $(SRC_CLIENT)

clean:
	$(RM) *~ *# *.o

fclean: clean
	$(RM) $(NAME_SERVEUR)
	$(RM) $(NAME_CLIENT)

re:	fclean all
