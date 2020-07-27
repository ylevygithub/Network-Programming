/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** In/Out operations on other socket
*/

#include "../my_teams.h"

void command(int i, homepage_t *general)
{
    char **command_tab = NULL;
    char const user_id[3];

    sprintf(user_id, "%d", general->client[i].uuid);
    if (strncmp(general->client[i].buffer, "/login", 6) == 0) {
        command_tab = my_str_to_word_array(general->client[i].buffer);
        general->client[i].name = malloc(sizeof(char) \
        * strlen(command_tab[1]) + 1);
        general->client[i].name = command_tab[1];
        general->client[i].name[(strlen(command_tab[1]) + 1)] = '\0';
        if (server_user_created(user_id, \
        general->client[i].name) == -1) {
            write(i, "you can't register your name\n", 30);
        }
    } else if (strncmp(general->client[i].buffer, "/use", 4) == 0) {
        function_use(general, i);
    }
    //else if (strncmp(general->client[i].buffer, "/send", 5) == 0) {
    //    send_command(general, i);
    //} 
    else {
        function_create(general, i, user_id);
    }
}

homepage_t *buffer_function(int readvalue, char *buff, homepage_t *general, \
int i)
{
    char rep[512];
    int it = 0;

    while (it != readvalue) {
        rep[it] = buff[it];
        it++;
    }
    rep[it] = '\0';
    general->client[i].buffer = malloc(sizeof(char) * readvalue + 1);
    it = 0;
    while (rep[it]) {
        general->client[i].buffer[it] = rep[it];
        it++;
    }
    general->client[i].buffer[it] = '\0';
    return (general);
}

void io_commands(data_t data, int i, homepage_t *general)
{
    int readvalue = 1;
    char buff[512];
    if (FD_ISSET(data.fd, &data.readfds)) {
        if ((readvalue = read(data.fd, buff, 512)) == 0) {
            close_terminal(data, i, general);
        }
        else {
            buffer_function(readvalue, buff, general, i);
            command(i, general);
        }
    }
}

void io_operation_on_other_socket(homepage_t *general, data_t data)
{
    for (int i = 0; i < general->max_clients; i++) {
        data.fd = general->client[i].uuid;
        io_commands(data, i, general);
    }
}
