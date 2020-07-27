/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** server loop
*/

#include "../my_teams.h"

void client_interractions(data_t data, int ss, homepage_t *general)
{
    if (FD_ISSET(ss, &data.readfds)) {
        data.new_socket = incoming_connection(data.cliaddr, ss, data.len);
        general->client = add_client_socket_to_array(general, data);
    }
    io_operation_on_other_socket(general, data);
}

data_t check_fd(data_t data)
{
    if (data.fd > 0)
        FD_SET(data.fd, &data.readfds);
    return (data);
}

data_t second_check_fd(data_t data)
{
    if (data.fd > data.maxfd)
        data.maxfd = data.fd;
    return (data);
}

int server_loop(int ss)
{
    homepage_t *general;
    general = malloc(sizeof(homepage_t));
    data_t data_server;
    general = initialise_all_clients_and_teams(general);
    data_server.len = sizeof(data_server.cliaddr);

    while (1) {
        FD_ZERO(&data_server.readfds);
        FD_SET(ss, &data_server.readfds);
        data_server.maxfd = ss;
        for (int i = 0; i < general->max_clients; i++) {
            data_server.fd = general->client[i].uuid;
            data_server = check_fd(data_server);
            data_server = second_check_fd(data_server);
        }
        data_server.fdready = select(data_server.maxfd + 1, \
        &data_server.readfds, NULL, NULL, NULL);
        check_error(data_server.fdready, "select()");
        client_interractions(data_server, ss, general);
    }
    return (0);
}
