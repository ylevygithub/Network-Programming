/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

/*When a client attempts to communicate with a server, it first sends a connection request that the server
must “accept”. For that purpose, the accept system call will come in handy.
Accept the first incoming connection and display the client’s connection information (IP address, port).
Then, write “Hello World!!!” to the socket and close it.*/
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netdb.h>
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

/*int accept(int sockfd, struct sockaddr *adresse, socklen_t *longueur);  */

int acceptConnection(void)
{
    int fd = createSocket();
    int myBind = configSocket();
    int myListen = initQueue();
    /* Nous pouvons maintenant accepter une connexion
       entrante à la fois grâce à accept(2) */
    int new_fd;
    struct sockaddr_in *peerAddr;
    socklen_t peer_addr_size;

    peer_addr_size = sizeof(struct sockaddr_in);
    new_fd = accept(fd, (struct sockaddr*)&peerAddr, &peer_addr_size);
    if (new_fd == -1)
        handle_error("error Accept");
    return (new_fd);
}
