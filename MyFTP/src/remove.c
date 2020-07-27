/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** remove function
*/

#include "my.h"

int remove_file(int sc, char *buff)
{
    int i = 5;
    int j = 0;
    char file[500];

    while (buff[i]) {
        file[j] = buff[i];
        i++;
        j++;
    }
    if (remove(file) == errno) {
        perror("remove function returned errno\n");
        exit(84);
    }
}
