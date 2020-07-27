/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** myftp
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        help(ac, av);
    else if (ac != 3)
        return (84);
    else
        return (create_serveur(ac, av));
    return (0);
}
