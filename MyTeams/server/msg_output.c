/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** msg_output
*/

#include "../my_teams.h"

void msg220(int sc)
{
    write(sc, "220 Service ready for new user.\n",
    strlen("220 Service ready for new user.\n"));
}

void msg221(int sc)
{
    write(sc, "221 Service closing control connection.\n",
    strlen("221 Service closing control connection.\n"));
}

int end_execution(int sc)
{
    msg221(sc);
    printf("client leave\n");
    close(sc);
    return (0);
}

void new_client(int sc)
{
    write(1, "New client : ", strlen("New client : "));
    msg220(sc);
}
