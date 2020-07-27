/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** create socket
*/

#include <netdb.h>
#include "../my_teams.h"

int create_socket(void)
{
    struct protoent	*proto;
    int	fd;

    if ((proto = getprotobyname("TCP")) == NULL) {
        printf("Cannot take protocole\n");
        return (84);
    }
    if ((fd = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1) {
        printf("Cannot create socket\n");
        return (84);
    }
    return (fd);
}
