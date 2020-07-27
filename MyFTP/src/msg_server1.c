/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** first server msg from the list
*/

#include "my.h"

void msg150(int sc)
{
    write(sc, "150 File status okay; about to open data connection.\n",
        strlen("150 File status okay; about to open data connection.\n"));
}

void msg200(int sc)
{
    write(sc, "200 Command okay.\n", strlen("200 Command okay.\n"));
}

void msg214(int sc)
{
    write(sc, "214 Help message.\n", strlen("214 Help message.\n"));
}

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
