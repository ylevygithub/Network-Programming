/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** second server msg from the list
*/

#include "my.h"

void msg225(int sc)
{
    write(sc, "225 Data connection open; no transfer in progress.\n",
        strlen("225 Data connection open; no transfer in progress.\n"));
}

void msg226(int sc)
{
    write(sc, "226 Closing data connection.\n",
        strlen("226 Closing data connection.\n"));
    write(sc, "Requested file action successful.\n",
        strlen("Requested file action successful.\n"));
}

void msg227(int sc)
{
    write(sc, "227 Entering Passive Mode (127,0,0,1,4,10).\n",
        strlen("227 Entering Passive Mode (127,0,0,1,4,10).\n"));
}

void msg230(int sc)
{
    write(sc, "230 User logged in, proceed.\n",
        strlen("230 User logged in, proceed.\n"));
}

void msg250(int sc)
{
    write(sc, "250 Requested file action okay, completed.\n",
        strlen("250 Requested file action okay, completed.\n"));
}
