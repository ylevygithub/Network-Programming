/*
** EPITECH PROJECT, 2020
** my teams
** File description:
** error function
*/

#include <stdio.h>
#include <unistd.h>
#include "../my_teams.h"

int my_error(char *str, int ss, int sc)
{
    printf("%s\n", str);
    if (ss != -1 && close(ss) == -1)
        printf("Cannot close socket\n");
    if (sc != -1 && close(sc) == -1)
        printf("Cannot close socket\n");
    return (84);
}

void check_error(int error, const char *msg)
{
    if (error < 0) {
        perror(msg);
        exit(84);
    }
}
