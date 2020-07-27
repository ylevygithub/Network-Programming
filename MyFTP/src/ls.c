/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** ls function
*/

#include "my.h"

void errno_ls(void)
{
    if (errno == EBADF) {
        perror("Cannot read file\n");
        exit(84);
    }
}

void my_ls(int sc)
{
    DIR *dir;
    struct dirent *ptr;
    int fisrtEntry = 0;

    if ((dir = opendir(".")) == NULL) {
        perror("Cannot open directory\n");
        exit(84);
    }
    while ((ptr = readdir(dir)) != NULL) {
            fisrtEntry++;
        if (ptr->d_name[0] != '.') {
            if (fisrtEntry == 1)
                write(sc, "\n", 1);
            write(sc, ptr->d_name, strlen(ptr->d_name));
            write(sc, "\n", 1);
        }
    }
    errno_ls();
}
