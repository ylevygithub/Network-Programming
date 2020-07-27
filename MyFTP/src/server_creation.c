/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** server creation
*/

#include "my.h"

int create_serveur(int ac, char **av)
{
    int ss;
    struct sockaddr_in sin;

    ss = create_socket();
    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi(av[1]));
    sin.sin_addr.s_addr = INADDR_ANY;
    if (bind(ss, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
        my_error("Cannot assign address to server", ss, -1);
    if (listen(ss, 40) == -1)
        my_error("Cannot create a queue", ss, -1);
    serveur_loop(ss);
    return (0);
}
