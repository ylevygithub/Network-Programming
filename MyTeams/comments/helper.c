/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** help function
*/

#include <stdio.h>
#include "../my_teams.h"

void help(void)
{
    printf("USAGE: ./myteams_server port\n\n\t");
    printf("port is the port number on which the server socket listens.\n");
}

int verif_args(char **av)
{
    int i = 0;

    while (av[1][i] != '\0') {
        if (av[1][i] >= '0' && av[1][i] <= '9')
            i++;
        else
            return (1);
    }
    return (0);
}