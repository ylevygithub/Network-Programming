/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** main server function
*/

#include "../my_teams.h"

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        help();
    else if (ac != 2 || verif_args(av) == 1)
        return (84);
    else {
        signal(SIGINT, handler);
        return (create_server(av));
    }
    return (0);
}
