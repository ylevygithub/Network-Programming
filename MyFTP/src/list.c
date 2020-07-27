/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** list function
*/

#include "my.h"

void errno_list(void)
{
    if (errno == EBADF) {
        perror("Cannot read file\n");
        exit(84);
    }
}

void opendir_fail(DIR *dir)
{
    if (dir == NULL) {
        perror("Cannot open directory\n");
        exit(84);
    }
}

void client_msg_list(int sc)
{
    msg150(sc);
    msg226(sc);
}

void my_list(int sc)
{
    DIR *dir = opendir(".");
    struct dirent *ptr;
    int fisrtEntry = 0;

    opendir_fail(dir);
    client_msg_list(sc);
    while ((ptr = readdir(dir)) != NULL) {
            fisrtEntry++;
        if (ptr->d_name[0] != '.') {
            if (fisrtEntry == 1)
                write(sc, "\n", 1);
            write(sc, ptr->d_name, strlen(ptr->d_name));
            write(sc, "\n", 1);
        }
    }
    errno_list();
}
