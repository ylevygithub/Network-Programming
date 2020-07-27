/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** serveur loop
*/

#include "my.h"

void end_execution(int sc, int ss)
{
    msg221(sc);
    printf("client leave\n");
    close(sc);
    exit(0);
}

void new_client(int sc)
{
    write(1, "New client : ", strlen("New client : "));
    msg220(sc);
}

int serveur_loop(int ss)
{
    pid_t pid;
    struct sockaddr_in s;
    int sc;
    int len;

    while (1) {
        len = sizeof(s);
        if ((sc = accept(ss, (struct sockaddr *)&s, (socklen_t *)&len)) == -1)
            my_error("Cannot accept client", ss, -1);
        if ((pid = fork()) == 0) {
            new_client(sc);
            len = strlen(strcat(inet_ntoa(s.sin_addr), "\n"));
            write(1, strcat(inet_ntoa(s.sin_addr), "\n"), len);
        while (1)
            if (execute(sc) == 0)
                end_execution(sc, ss);
        exit(0);
        }
    }
}
