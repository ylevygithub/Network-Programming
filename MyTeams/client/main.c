/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** main client function
*/

#include "../my_teams.h"
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 512

void help(void)
{
    printf("USAGE: ./myteams_cli ip port\n\t");
    printf("ip   is the server ip address on which the server socket \
    listens\n\t");
    printf("port is the port number on which the server socket listens\n");
}

int my_compare(char *name, char *str)
{
    int it = 0;

    if (strlen(name) > strlen(str))
        return (1);
    while (name[it] && name[it] != '\n') {
        if (name[it] != str[it])
            return (1);
        it++;
    }
    if (str[it] != '/')
        return (1);
    return (0);
}

int find_user(char *name, char **users)
{
    int it = 0;

    while (users[it]) {
        if (my_compare(name, users[it]) == 0)
            return (it);
        it++;
    }
    return (-1);
}

int main(int ac, char **av)
{
    int sockfd;
    struct sockaddr_in servaddr;

    if (ac != 3) {
        help();
        return (84);
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket creation failed");
        exit(0);
    }
    filling_server_info(sockfd, servaddr, av);
}
