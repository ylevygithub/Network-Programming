/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** header file
*/

#ifndef MY_TEAMS
#define MY_TEAMS

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include <stddef.h>
#define MAX_NAME_LENGTH 32
#define MAX_BODY_LENGTH 512
#define MAX_DESCRIPTION_LENGTH 255

struct data_s
{
    int new_socket;
    int max_clients;
    int fd;
    int maxfd;
    int fdready;
    int len;
    char buffer[MAX_BODY_LENGTH];
    fd_set readfds;
    struct sockaddr_in cliaddr;
    int *client_socket;
};
typedef struct data_s data_t;

/******************helper.c****************/
void help(void);
int verif_args(char **);
/******************error.c****************/
int my_error(char *, int, int);
void check_error(int, const char *);
/******************create_socket.c****************/
int create_socket(void);
/******************create_server.c****************/
int create_serveur(char **);
/******************server_loop.c****************/
void msg220(int);
void msg221(int);
int end_execution(int);
void new_client(int);
int serveur_loop(int);

/***********server/initialising_clients.c**********/
int *initialise_all_clients(int, int *);
/***********add_client_sock_to_array.c*************/
int *add_client_socket_to_array(data_t);
/***********incoming_connection.c*************/
int incoming_connection(struct sockaddr_in, int, int );
/***********IO_operations.c*************/
void IO_operation_on_other_socket(data_t);
void IO_commands(data_t data, int i);
void close_terminal(data_t data, int i);
void logout(data_t data, int i);

#endif
