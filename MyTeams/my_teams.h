/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** header file
*/

#ifndef MY_TEAMS
#define MY_TEAMS

#include <sys/types.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <signal.h>
#include "lib/include/logging_client.h"
#include "lib/include/logging_server.h"
#define MAX_NAME_LENGTH 32
#define MAX_BODY_LENGTH 512
#define MAX_DESCRIPTION_LENGTH 255

typedef struct thread_s {
    int uuid;
    char *title;
    char message[MAX_BODY_LENGTH];
    char **comments;
} thread_t;

typedef struct channel_s {
    int uuid;
    int nb_channel;
    char *name;
    char *description;
    thread_t *thread;
} channel_t;

typedef struct client_s
{
    char *name;
    int uuid;
    int *uuid_team;
    int current_uuid_team;
    int current_channel;
    int nb_team;
    char *buffer;
} client_t;

typedef struct teams_s {
    int uuid;
    int max_clients;
    char *name;
    char *description;
    channel_t *channel;
} teams_t;

typedef struct homepage_s {
    teams_t *teams;
    client_t *client;
    int max_clients;
    int max_teams;
} homepage_t;

typedef struct data_s
{
    int new_socket;
    int fd;
    int maxfd;
    int fdready;
    int len;
    fd_set readfds;
    struct sockaddr_in cliaddr;
} data_t;

/******************helper****************/
void help(void);
int verif_args(char **);
/******************error****************/
int my_error(char *, int, int);
void check_error(int, const char *);
/******************creation****************/
int create_socket(void);
int create_server(char **);
/******************server_loop****************/
void msg220(int);
void msg221(int);
int end_execution(int);
void new_client(int);
int server_loop(int);
void client_interractions(data_t data, int ss, homepage_t *general);

/******************client_loop****************/
void filling_server_info(int sockfd, \
struct sockaddr_in servaddr, char **av);
char *my_prompt(void);
size_t count(char *str);
int check_recive(char *str, char *command);
char *my_strcpy(char *str);
int find_user(char *name, char **users);
char *take_info(char *str, int x);
int count_to_first(char *str);
int last_size(char *str);

/***********set/initialisation clients**********/
homepage_t *initialise_all_clients_and_teams(homepage_t *);
client_t *add_client_socket_to_array(homepage_t *, data_t);
int incoming_connection(struct sockaddr_in, int, int);
/***********IO_operations*************/
void io_operation_on_other_socket(homepage_t *, data_t);
void io_commands(data_t data, int i, homepage_t *);
void close_terminal(data_t data, int i, homepage_t *);
void logout(data_t data, int i, homepage_t *);
void function_create(homepage_t *general, int i, const char *user_id);
void function_use(homepage_t *general, int i);

/************tool_function**********/
int find_word_in_file(FILE *fptr, const char *word);
char **my_str_to_word_array(char *str);
int analyse_team_name(teams_t team, FILE *fptr_add, int socket, \
char const *team_id);
int analyse_user_name(char const *command_tab, FILE *fptr_read, \
FILE *fptr_add, int socket);
char const *check_nb_of_team(void);
int fill_team(char **command_client, homepage_t *general, \
char const *nb_of_teams, client_t client);
void create_folder_of_team(char const *team_name);
homepage_t *fill_channel(char **command_client, homepage_t *general, \
int uuid_team);
char *create_folder_of_channel(char *team_name, channel_t *channel);
void add_description_channel(channel_t channel, char *team_name, int team_id);
char *my_open_read(const char *path);
char **parsing_user(char const *str);
int nb_arg_of_use(char **command_tab);

/************server_function**********/
int server_team_created(char const *team_id, teams_t team, \
char const *user_id);
void launch_server_creation(int i, char **command_tab, homepage_t *general, \
const char *user_id);
int server_user_created(char const *user_id, char const *user_name);
void server_channel_created(channel_t *channel, int team_uuid, \
char *team_name, char const *user_id);
void launch_channel_creation(int i, char **command_tab, homepage_t *general, \
const char *user_id);
/************function_for_good_working_of_lib**********/
int dlsym_one(char const *fct_name, char const *arg);
int dlsym_two(char const *fct_name, char const *arg1, char const *arg2);
int dlsym_three(char const *fct_name, char const *arg1,
char const *arg2, char const *arg3);
/************ctrl_c_shutdown.c**********/
void handler(int);

#endif
