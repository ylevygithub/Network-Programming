/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** add a client to the array of client_sockets
*/

#include "../my_teams.h"

client_t *add_client_socket_to_array(homepage_t *general, data_t data)
{
    for (int i = 0; i < general->max_clients; i++) {
        if (general->client[i].uuid == 0) {
            general->client[i].uuid = data.new_socket;
            printf("Adding to list of sockets as %d\n", i);
            break;
        }
    }
    return (general->client);
}
