/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** add a client to the array of client_sockets
*/

#include "../my_teams.h"

int *add_client_socket_to_array(data_t data)
{
    //add new socket to array of sockets
    for (int i = 0; i < data.max_clients; i++) {
        //if position is empty that means we have to fill this place
        if (data.client_socket[i] == 0) {
            data.client_socket[i] = data.new_socket;
            printf("Adding to list of sockets as %d\n", i);
            break;
        }
    }
    return (data.client_socket);
}
