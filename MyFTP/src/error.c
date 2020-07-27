/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** error function
*/

#include "my.h"

void my_error(char *str, int ss, int sc)
{
    printf("%s\n", str);
    if (ss != -1 && close(ss) == -1)
        printf("Cannot close socket\n");
    if (sc != -1 && close(sc) == -1)
        printf("Cannot close socket\n");
    exit(84);
}
