/*
** EPITECH PROJECT, 2020
** open_read
** File description:
** fonction for open and read a file
*/

#include "../my_teams.h"

char *my_open_read(const char *path)
{
    char str_tab[30000];
    int x = 0;
    int it = 0;
    char *res;
    int fd;

    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    if (read(fd, str_tab, 30000) == 0)
        return (NULL);
    it = strlen(str_tab);
    res = malloc(sizeof(char) * it + 1);
    while (x < it) {
        res[x] = str_tab[x];
        x++;
    }
    res[x] = '\0';
    return (res);
}

int start_point(char *str, int x)
{
    int it = 0;
    int b = 0;

    while (b < x && str[it]) {
        if (str[it] == '/')
            b = b + 1;
        it++;
    }
    return (it);
}

char *take_info(char *str, int x)
{
    int it = start_point(str, x);
    int b = it;
    int save = 0;
    char *rep;

    while (str[it] && str[it] != '/') {
        it++;
        save++;
    }
    rep = malloc(sizeof(char) * save + 1);
    it = 0;
    while (str[b] && str[b] != '/') {
        rep[it] = str[b];
        it++;
        b++;
    }
    rep[it] = '\0';
    return (rep);
}