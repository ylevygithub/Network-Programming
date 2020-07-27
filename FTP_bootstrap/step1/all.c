/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 500

/*int getaddrinfo(const char *node, const char *service,
                const struct addrinfo *hints,
                struct addrinfo **res);
*/
/*int connect(int sockfd, const struct sockaddr *serv_addr,
            socklen_t addrlen);*/
int main(int ac, char **av)
{
    struct addrinfo hints;
    struct addrinfo *res, *res2;
    int fd, fd2;
    struct sockaddr_storage peer_addr;
    socklen_t peer_addr_len;
    ssize_t nread;
    char buf[BUF_SIZE];

    if (ac != 2) {
        fprintf(stderr, "Usage: %s port\n", av[0]);
        exit(EXIT_FAILURE);
    }
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;    /* Allow IPv4 */
    hints.ai_socktype = SOCK_STREAM; /* STREAM socket */
    hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
    hints.ai_protocol = 0;          /* Any protocol */
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

    fd2 = getaddrinfo(NULL, av[1], &hints, &res);
    if (fd2 != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(fd2));
        exit(EXIT_FAILURE);
    }

    /* getaddrinfo() returns a list of address structures.
       Try each address until we successfully bind(2).
       If socket() (or bind()) fails, we (close the socket
       and) try the next address. */

    for (res2 = res; res2 != NULL; res2 = res2->ai_next) {
        fd = socket(res2->ai_family, res2->ai_socktype,
                res2->ai_protocol);
        if (fd == -1)
            continue;
        if (bind(fd, res2->ai_addr, res2->ai_addrlen) == 0){
            break;                  /* Success */
        }
        close(fd);
    }
    if (res2 == NULL) {               /* No address succeeded */
        fprintf(stderr, "Could not bind\n");
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(res);           /* No longer needed */

    /* Read datagrams and echo them back to sender */

    for (;;) {
        peer_addr_len = sizeof(struct sockaddr_storage);
        nread = recvfrom(fd, buf, BUF_SIZE, 0,
                (struct sockaddr *) &peer_addr, &peer_addr_len);
        if (nread == -1)
            continue;               /* Ignore failed request */

        char host[NI_MAXHOST], service[NI_MAXSERV];

        fd2 = getnameinfo((struct sockaddr *) &peer_addr,
                        peer_addr_len, host, NI_MAXHOST,
                        service, NI_MAXSERV, NI_NUMERICSERV);
       if (fd2 == 0)
            printf("Received %ld bytes from %s:%s\n",
                    (long) nread, host, service);
        else
            fprintf(stderr, "getnameinfo: %s\n", gai_strerror(fd2));

        if (sendto(fd, buf, nread, 0,
                    (struct sockaddr *) &peer_addr,
                    peer_addr_len) != nread)
            fprintf(stderr, "Error sending response\n");
    }
}
