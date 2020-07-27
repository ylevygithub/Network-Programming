/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** clean str
*/

#include "my.h"

int end_str(char *str)
{
    int i = strlen(str) - 1;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i--;
    }
    return (i);
}

char *epure_str(char *str)
{
    int i = 0;
    int j = 0;
    int end = end_str(str);
    char *tmp = malloc(sizeof(char) * 4096);

    while (str[i] == ' ' || str[i] == '\t')
    i++;
    while (i <= end) {
        if (str[i] != ' ' || str[i + 1] == ' ' ||
            str[i] != '\t') {
            tmp[j] = str[i];
            i++;
            j++;
        }
        while (str[i] == ' ' && str[i + 1] == ' '
           || str[i] == '\t')
            i++;
    }
    tmp[j] = '\0';
    return (tmp);
}
