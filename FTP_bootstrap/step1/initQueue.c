/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

/*
int listen(int sockfd, int backlog);
    Renvoie 0 si il réussit, ou -1 en cas d'échec.
In order to communicate with your server, you must initialize a queue for clients to wait until their connection request is taken into account.
Initialize a queue with a sufficient length.
This highly evolved process was shamefully inspired from post offices and child benefit
offices treatment processes. . .
However, we will ask you to be more effective than them in dealing with your clients’
requests. . .
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>
#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)
#define LISTEN_BACKLOG 50//pour le deuxieme argument de listen

int createSocket(void)
{
    int fd = socket(PF_INET, SOCK_STREAM, 0);

    if (fd == -1)
        return (-1);
    else
        return (fd);
}

/*bind = Fournir un nom a une socket
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
uint16_t htons(uint16_t hostshort);
*/
int configSocket(void)
{
    int fd = createSocket();
    int myBind;
    if (fd == -1)
        handle_error("error Socket");//EXIT FAILURE
    struct sockaddr_in *addr;
    socklen_t addrlen;
/*htons ====> Conversions d'ordre des octets entre un hôte et un réseau*/
    uint16_t conversion = htons(INADDR_ANY);//INADDR_ANY signifie un attachement à n'importe quelle adresse
    addr->sin_family = AF_INET; //internet
    addr->sin_port = conversion;//any port
    addr->sin_addr.s_addr = sizeof(struct sockaddr_in);
    addrlen = addr->sin_addr.s_addr;
    myBind = bind(fd, addr, addrlen);
    if (myBind == -1)
        handle_error("error Bind");
    return (myBind);
}

int initQueue(void)
{
    int fd = createSocket();
    int myBind = configSocket();
    int myListen = listen(fd, LISTEN_BACKLOG);
    if (myListen == -1)
        handle_error("error Listen");
    return (myListen);
}