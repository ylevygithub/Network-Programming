/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** strtowordtab function
*/

#include "my.h"

int count_char(char *str, int *x)
{
    int len = 0;

    while (str[*x] != ' ' && str[*x] != '\0') {
        len++;
        *x = *x + 1;
    }
    return (len);
}

int count_word(char *str)
{
    int i = 0;
    int counter = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\0')
            counter++;
        i++;
    }
    return (counter);
}

char **str_to_word_tab(char *str, int count)
{
    int i = 0;
    int j = 0;
    int x = 0;
    char **map = malloc(sizeof(char *) * count_word(str) + 1);

    while (i < count_word(str) + 1) {
        count = x;
        j = 0;
        map[i] = malloc(sizeof(char) * count_char(str, &x) + 1);
        while (str[count] != ' ' && str[count] != '\0') {
                map[i][j] = str[count];
                count++;
                j++;
        }
        map[i][j] = '\0';
        x = x + 1;
        i++;
    }
    map[count_word(str) + 1] = NULL;
    return (map);
}
