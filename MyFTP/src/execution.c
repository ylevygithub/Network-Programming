/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** execution of the commands
*/

#include "my.h"
int mdpEntered = 0;
int userEntered = 0;

void verif_read(int nb_read)
{
    if (nb_read == -1) {
        perror("Error read\n");
        exit(84);
    }
}

int user_cmd(char *buff, int sc)
{
    ((strncmp(buff, "USER Anonymous", 14) == 0 ||
        strncmp(buff, "USER cDUvjsX5", 13) == 0) && mdpEntered == 0)
    ? (userEntered = 1, msg331(sc)) : ((strncmp(buff, "PASS ", 5) == 0
        && userEntered != 0 && mdpEntered == 0) ? (mdpEntered = 1, msg230(sc))
    : ((mdpEntered == 0 && (strncmp(buff, "USER Anonymous", 14) != 0 ||
    strncmp(buff, "PASS ", 5) != 0 || strncmp(buff, "QUIT", 4) != 0)) ?
    msg530(sc) : (strncmp(buff, "ls", 2) == 0 ? my_ls(sc) :
    (strncmp(buff, "LIST ", 5) == 0 ? msg425(sc) : (strncmp(buff, "LIST", 4)
    == 0 ? my_list(sc) : (strncmp(buff, "PWD", 3) == 0 ? my_pwd(sc) :
    (strncmp(buff, "DELE ", 5) == 0 ? (remove_file(sc, buff), msg250(sc)) :
    (strncmp(buff, "CDUP", 4) == 0 ? (chdir(".."), msg200(sc)) :
    (strncmp(buff, "CWD", 3) == 0 ? msg250(sc) : (strncmp(buff, "PORT", 4)
    == 0 ? msg501(sc) : (strncmp(buff, "PASV ", 5) == 0 ? msg550(sc) :
    (strncmp(buff, "PASV", 4) == 0 ? msg227(sc) :
    (strncmp(buff, "NOOP", 4) == 0 ? msg200(sc) : (strncmp(buff, "RETR", 4)
    == 0 ? msg425(sc) : (strncmp(buff, "STOR", 4) == 0 ? msg425(sc) :
    (strncmp(buff, "HELP", 4) == 0 ? help_command(sc)
    : msg500(sc)))))))))))))))));
    return (1);
}

int	execute(int sc)
{
    size_t c = 32;
    int	nb_read;
    char buff[500];

    while (1) {
        nb_read = read(sc, buff, 500);
        verif_read(nb_read);
        if (strncmp(buff, "QUIT", 4) == 0)
            return (0);
        return (user_cmd(buff, sc));
    }
}
