/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** manage ctrl c signal
*/

#include "../my_teams.h"

void handler(int sig)
{
    if (signal(sig, handler) != SIG_ERR)
        printf("\nCtrl-C was hit.\n");
    else {
        printf("SIG_ERR was received\n");
        exit(84);
    }
}

