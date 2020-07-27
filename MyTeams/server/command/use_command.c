/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** server command
*/

#include "../../my_teams.h"

int nb_arg_of_use(char **command_tab)
{
    int i = 0;

    while (command_tab[i] != NULL)
        i++;
    return (i);
}

void two_arg(homepage_t *general, char **command_tab, int i)
{
    char *message = malloc(sizeof(char) \
    * (27 + strlen(general->teams[atoi(command_tab[1])].name + \
    strlen(general->teams[atoi(command_tab[1])].name))) + 1);
    general->client[i].current_uuid_team = atoi(command_tab[1]);
    general->client[i].current_channel = atoi(command_tab[2]);
    strcpy(message, "You are in the channel ");
    strcat(message, general->teams[atoi(command_tab[1])].\
    channel[atoi(command_tab[2])].name);
    strcat(message, " of ");
    strcat(message, general->teams[atoi(command_tab[1])].name);
    send(general->client[i].uuid, message, strlen(message), 0);
    free(message);
}

void function_use(homepage_t *general, int i)
{
    char **command_tab = NULL;
    int nb_arg = 0;
    command_tab = my_str_to_word_array(general->client[i].buffer);
    nb_arg = (nb_arg_of_use(command_tab) - 1);

    if (nb_arg == 1) {
        char *message = malloc(sizeof(char) * \
        (22 + strlen(general->teams[atoi(command_tab[1])].name)) + 1);
        general->client[i].current_uuid_team = atoi(command_tab[1]);
        printf("current team: %i\n", general->client[i].current_uuid_team);
        strcpy(message, "You are in the team: ");
        strcat(message, general->teams[atoi(command_tab[1])].name);
        send(general->client[i].uuid, message, strlen(message), 0);
        free(message);
    }
    if (nb_arg == 2)
        two_arg(general, command_tab, i);
}