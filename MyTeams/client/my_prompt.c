/*
** EPITECH PROJECT, 2020
** my_prompt
** File description:
** my prompt
*/

#include "../my_teams.h"

char *my_prompt(void)
{
    char *str;
    char *result;
    size_t len = 0;
    int it = 0;

    result = malloc(sizeof(char) * getline(&str, &len, stdin));
    while (str[it]) {
        result[it] = str[it];
        it++;
    }
    result[it] = '\0';
    return (result);
}

size_t count(char *str)
{
    int it = 0;
    size_t line = 0;

    while (str[it]) {
        it++;
        line++;
    }
    return (line - 1);
}

char *my_strcpy(char *str)
{
    char *rep = malloc(sizeof(char) * strlen(str) + 1);
    int it = 0;

    while (str[it]) {
        rep[it] = str[it];
        it++;
    }
    rep[it] = '\0';
    return (rep);
}