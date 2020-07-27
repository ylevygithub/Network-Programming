/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** server creation
*/

#include "../my_teams.h"

int create_server(char **av)
{
    int ss = create_socket();
    struct sockaddr_in server;

    if (ss == 84)
        return (84);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(av[1]));
    server.sin_addr.s_addr = INADDR_ANY;
    if (bind(ss, (const struct sockaddr *)&server, sizeof(server)) == -1)
        if (my_error("Cannot assign address to server", ss, -1) == 84)
            return (84);
    if (listen(ss, 40) == -1)
        if (my_error("Cannot create a queue", ss, -1) == 84)
            return (84);
    return (server_loop(ss));
}
