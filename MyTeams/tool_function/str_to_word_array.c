/*
** EPITECH PROJECT, 2020
** str_to_word_array
** File description:
** str_to_word_array
*/

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

int check_nb_lines(char *str)
{
    int i = 0;
    int k = 1;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            k++;
        i++;
    }
    return (k);
}

char **allocating_array(char *str)
{
    char **array;
    int i = 0;
    int space = check_nb_lines(str);

    array = malloc(sizeof(char *) * (space + 1));
    while (i < space) {
        array[i] = malloc(sizeof(char) * (strlen(str) + 1));
	i++;
    }
    array[space + 1] = NULL;
    return (array);
}

char **my_str_to_word_array(char *str)
{
    char **array = allocating_array(str);
    int i = 0;
    int k = 0;
    int j = 0;

    while (str[k] != '\0') {
        while (str[k] != ' ' && str[k] != '\0') {
            array[i][j] = str[k];
            k++;
            j++;
        }
        array[i][j] = '\0';
        if (str[k] == ' ')
            k++;
        i++;
        j = 0;
    }
    return (array);
}