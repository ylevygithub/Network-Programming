/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** server command
*/

#include "../../my_teams.h"

void close_terminal(data_t data, int i, homepage_t *general)
{
    char *ip;
    uint16_t port;
    getpeername(data.fd, (struct sockaddr*)&data.cliaddr, \
    (socklen_t *)&data.len);
    ip = inet_ntoa(data.cliaddr.sin_addr);
    port = ntohs(data.cliaddr.sin_port);
    printf("Host disconnected , ip : %s , port : %d \n", ip, port);
    close(data.fd);
    general->client[i].uuid = 0;
}