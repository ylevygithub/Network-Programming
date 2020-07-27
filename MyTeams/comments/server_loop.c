/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** server loop
*/
#include "../my_teams.h"

void msg220(int sc)
{
    write(sc, "220 Service ready for new user.\n",
        strlen("220 Service ready for new user.\n"));
}

void msg221(int sc)
{
    write(sc, "221 Service closing control connection.\n",
        strlen("221 Service closing control connection.\n"));
}

int end_execution(int sc)
{
    msg221(sc);
    printf("client leave\n");
    close(sc);
    return (0);
}

void new_client(int sc)
{
    write(1, "New client : ", strlen("New client : "));
    msg220(sc);
}

int serveur_loop(int ss)
{
    data_t data;
    // int new_socket, fd, maxfd, fdready, len;
    // char buffer[MAX_BODY_LENGTH];
    // fd_set readfds;
    // struct sockaddr_in cliaddr;
    data.max_clients = 40;
    data.client_socket = malloc(sizeof(int) * 40);
    data.client_socket = initialise_all_clients(data.max_clients, data.client_socket);
    data.len = sizeof(data.cliaddr);
    // int *client_socket = malloc(sizeof(int) * 40);
    // client_socket = initialise_all_clients(max_clients, client_socket);
    // len = sizeof(cliaddr);

    while(1) {
        FD_ZERO(&data.readfds);
        FD_SET(ss, &data.readfds);
        data.maxfd = ss;
        for (int i = 0; i < data.max_clients; i++) {
            data.fd = data.client_socket[i];
            if (data.fd > 0)
                FD_SET(data.fd, &data.readfds);
            if (data.fd > data.maxfd)
                data.maxfd = data.fd;
        }
        data.fdready = select(data.maxfd + 1, &data.readfds, NULL, NULL, NULL);
        check_error(data.fdready, "select()");
        if (FD_ISSET(ss, &data.readfds)) {
            data.new_socket = incoming_connection(data.cliaddr, ss, data.len);
            data.client_socket = add_client_socket_to_array(data);
        }
        IO_operation_on_other_socket(data);
    }
    return (0);
}
