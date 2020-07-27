/*
** EPITECH PROJECT, 2020
** count_print
** File description:
** count and print
*/

#include "stdio.h"
#include "stdlib.h"

int count_to_first(char *str)
{
    int it = 0;

    while (str[it] != '\0' && str[it] != ' ') {
        it++;
    }
    return (it);
}

int last_size(char *str)
{
    int it = 0;
    int x = 0;
    int rep = 0;

    while (str[it] || x < 2) {
        if (str[it] == ' ') {
            x++;
        }
        it++;
    }
    while (str[it]) {
        it++;
        rep++;
    }
    return (rep);
}