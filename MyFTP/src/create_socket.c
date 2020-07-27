/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** create socket
*/

#include "my.h"

int create_socket(void)
{
    struct protoent	*proto;
    int	fd;

    if ((proto = getprotobyname("TCP")) == NULL) {
        printf("Cannot take protocole\n");
        exit(84);
    }
    if ((fd = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1) {
        printf("Cannot create socket\n");
        exit(84);
    }
    return (fd);
}
