/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** main client function
*/

#include "../my_teams.h"

void filling_server_info(int sockfd, \
struct sockaddr_in servaddr, char **av)
{
    char *command;
    char buffer[512];
    char test[100];
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(av[2]));
    servaddr.sin_addr.s_addr = inet_addr(av[1]);
    if (connect(sockfd, (struct sockaddr*)&servaddr,
        sizeof(servaddr)) < 0)
        printf("\n Error : Connection Failed \n");
    strcpy(buffer, "Hello Server!!!\n");
    send(sockfd, buffer, 16, 0);
    sleep(1);
    printf("Message from server: ");
    read(sockfd, test, sizeof(test));
    puts(test);
    command = my_prompt();
    while (strcmp(command, "/logout\n") != 0) {
        strcpy(buffer, command);
        send(sockfd, buffer, count(command), 0);
        read(sockfd, test, sizeof(test));
        if (check_recive(my_strcpy(test), command) == 0)
            puts(test);
        free(command);
        command = my_prompt();
    }
    close(sockfd);
}