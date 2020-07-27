/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** pwd function
*/

#include "my.h"

int my_pwd(int sc)
{
    char *str;

    if ((str = getenv("PWD")) == NULL) {
        printf("PATH not found\n");
        return (0);
    }
    write(sc, "257 ", 4);
    write(sc, str, strlen(str));
    write(sc, " created.\n", 10);
    return (1);
}
