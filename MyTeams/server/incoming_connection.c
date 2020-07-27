/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** incoming connection
*/

#include "../my_teams.h"

int incoming_connection(struct sockaddr_in cliaddr, int ss, int len)
{
    char *ip;
    uint16_t port;
    char* message = "Hello Student of Bruxels!\r\n";
    int new_socket = accept(ss, (struct sockaddr *)&cliaddr, (socklen_t *)&len);

    check_error(new_socket, "accept()");
    new_client(new_socket);
    ip = inet_ntoa(cliaddr.sin_addr);
    port = ntohs(cliaddr.sin_port);
    printf("from socket fd : %d , ip : %s , port : %d\n", new_socket, ip, port);
    if (send(new_socket, message, \
        strlen(message), 0) != (ssize_t)strlen(message))
        perror("send()");
    puts("A new student arrives in our Epitech!");
    return (new_socket);
}
