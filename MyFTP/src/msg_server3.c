/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** third server msg from the list
*/

#include "my.h"

void msg331(int sc)
{
    write(sc, "331 User name okay, need password.\n",
        strlen("331 User name okay, need password.\n"));
}

void msg425(int sc)
{
    write(sc, "425 Can't open data connection.\n",
        strlen("425 Can't open data connection.\n"));
}

void msg500(int sc)
{
    write(sc, "500 Syntax error, command unrecognized.\n",
        strlen("500 Syntax error, command unrecognized.\n"));
}

void msg501(int sc)
{
    write(sc, "501 Syntax error in parameters or arguments.\n",
        strlen("501 Syntax error in parameters or arguments.\n"));
}

void msg530(int sc)
{
    write(sc, "530 Not logged in.\n", strlen("530 Not logged in.\n"));
}
