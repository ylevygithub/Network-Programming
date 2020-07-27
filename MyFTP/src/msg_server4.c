/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** fourth server msg from the list
*/

#include "my.h"

void msg550(int sc)
{
    write(sc, "550 Requested action not taken.\n",
        strlen("550 Requested action not taken.\n"));
}
