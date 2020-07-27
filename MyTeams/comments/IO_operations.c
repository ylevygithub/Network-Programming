/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** In/Out operations on other socket
*/

#include "../my_teams.h"

void close_terminal(data_t data, int i)
{
    char *ip;
    uint16_t port;
    //Somebody disconnected , get his details and print  
    getpeername(data.fd, (struct sockaddr*)&data.cliaddr, (socklen_t *)&data.len);
    ip = inet_ntoa(data.cliaddr.sin_addr);
    port = ntohs(data.cliaddr.sin_port);
    printf("Host disconnected , ip : %s , port : %d \n", ip, port);
    //Close the socket and mark as 0 in list for reuse  
    close(data.fd);
    data.client_socket[i] = 0;
}

void logout(data_t data, int i)
{
    if (strncmp(data.buffer, "logout", 6) == 0)
        close_terminal(data, i);
}

void IO_commands(data_t data, int i)
{
    int readvalue = 1;

    if (FD_ISSET(data.fd, &data.readfds)) {
        //Check if it was for closing , and also read the  
        //incoming message  
        if ((readvalue = read(data.fd, data.buffer, MAX_BODY_LENGTH)) == 0)//eof
            close_terminal(data, i);
        else {
            logout(data, i);
        }
    }
}

void IO_operation_on_other_socket(data_t data)
{
    //else its some IO operation on some other socket 
    for (int i = 0; i < data.max_clients; i++) {
        data.fd = data.client_socket[i];
        IO_commands(data, i);
    }
}
