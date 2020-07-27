/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** initialise all the clients before the big loop
*/

#include "../my_teams.h"

int *initialise_all_clients(int max_clients, int *client_socket)
{
    //initialise all client_socket[] to 0 so not checked  
    for (int i = 0; i < max_clients; i++)
        client_socket[i] = 0;
    return (client_socket);
}
