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
    char* message = "Hello Client\n";
    int new_socket = accept(ss, (struct sockaddr *)&cliaddr, (socklen_t *)&len);

    check_error(new_socket, "accept()");
    //inform user of socket number - used in send and receive commands  
    new_client(new_socket);
    ip = inet_ntoa(cliaddr.sin_addr);
    port = ntohs(cliaddr.sin_port);
    printf("from socket fd : %d , ip : %s , port : %d\n", new_socket, ip, port);
    //send new connection greeting message  
    if (send(new_socket, message, strlen(message), 0) != (ssize_t)strlen(message))
        perror("send()");
    puts("Welcome message sent successfully");
    return (new_socket);
}
