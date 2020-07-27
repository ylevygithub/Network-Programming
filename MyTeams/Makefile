##
## EPITECH PROJECT, 2020
## myteams
## File description:
## Makefile
##

NAME_server	=	myteams_server
NAME_CLIENT		=	myteams_cli

SRC_server		=	tool_function/str_to_word_array.c	\
					tool_function/open_read.c \
					tool_function/parsing_user.c	\
					tool_function/teams_function/check_nb_team.c	\
					tool_function/teams_function/create_team.c	\
					tool_function/user_function/create_user.c	\
					tool_function/channel_function/create_channel.c	\
					server/create_socket.c \
					server/error.c \
					server/helper.c \
					server/main.c \
					server/server_creation.c \
					server/server_loop.c \
					server/initialising_clients_and_teams.c \
					server/incoming_connection.c \
					server/io_operations.c \
					server/add_client_sock_to_array.c	\
					server/msg_output.c	\
					server/ctrl_c_shutdown.c	\
					server/command/close_client.c	\
					server/command/command_create.c	\
					server/command/launch_create.c	\
					server/command/use_command.c

SRC_CLIENT		=	client/main.c \
					client/my_prompt.c \
					client/client_loop.c	\
					client/check_message_from_serv.c	\
					tool_function/open_read.c \
					tool_function/str_to_word_array.c \
					tool_function/parsing_user.c \
					lib/count_print.c

OBJ_server		=	$(SRC_server:.c=.o)
OBJ_CLIENT		=	$(SRC_CLIENT:.c=.o)

CFLAGS			=	-W -Wall -Wextra

RM				=	rm -rf

all:
	gcc -o $(NAME_server) $(CFLAGS) $(SRC_server) -ldl -L./lib/include/ -lmyteams
	gcc -o $(NAME_CLIENT) $(CFLAGS) $(SRC_CLIENT) -ldl -L./lib/include/ -lmyteams

clean:
	$(RM) *~ *# *.o

fclean: clean
	$(RM) $(NAME_server)
	$(RM) $(NAME_CLIENT)

re:	fclean all
