/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** help
*/

#include "my.h"

void help(int ac, char **av)
{
    printf("USAGE: ./myftp port path\n\t");
    printf("port is the port number on which the server socket listens\n\t");
    printf("path is the path to the home directory for the Anonymous user\n");
}

void help_command(int sc)
{
    const char *pathname = "help.txt";
    int size;
    int fd;
    char *buff;

    msg214(sc);
    fd = open(pathname, O_RDONLY);
    struct stat jack;
    stat(pathname, &jack);
    size = jack.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    buff[size] = '\0';
    write(sc, buff, strlen(buff));
    free(buff);
}
