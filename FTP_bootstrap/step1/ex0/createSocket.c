/*
** EPITECH PROJECT, 2020
** 
** File description:
** 
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#define handle_error(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

int socket(int domain, int type, int protocol);

int createSocket(void)
{
    int fd = socket(PF_INET, SOCK_STREAM, 0);
    if (fd == -1)
        return (-1);
    else
        return (fd);
}
int main(int ac, char **av)
{
    int fd = createSocket();
    if (fd == -1)
        handle_error("error socket");
    else
        printf("Socket was created successfully");
    return (0);
}
/*
socket() crée un point de communication, et renvoie un descripteur.
Le parametre domain indique le domaine de communication pour le dialogue; ceci selectionne la famille de protocole à employer.
Nous connaissons deja lequel nous allons employer car nous travaillons avec IPv4

NOM          Utilisation                 Page
PF_INET      Protocoles internet IPv4    ip(7)

La socket a le type indiqué, ce qui définit la sémantique des communications. Les types actuellement définis sont :
   SOCK_STREAM
         Support de dialogue garantissant l'intégrité, fournissant un flux de données binaires, et intégrant un mécanisme pour les transmissions de données hors-bande.
   ...
Une socket SOCK_STREAM doit être dans un état connecté avant que des données puisse y être lues ou écrites. 
Une connexion sur une autre socket est établie par l'appel système connect(2). 
Une fois connectée, les données y sont transmises par read(2) et write(2) ou par des variantes de send(2) et recv(2). 
Quand une session se termine, on referme la socket avec close(2). 
Les données hors-bande sont envoyées ou reçues en utilisant send(2) et recv(2).
*/