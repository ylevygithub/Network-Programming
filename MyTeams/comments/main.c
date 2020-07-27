/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** main server function
*/

#include <string.h>
#include "../my_teams.h"

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        help();
    else if (ac != 2 || verif_args(av) == 1)
        return (84);
    else
        return (create_serveur(av));
    return (0);
}
