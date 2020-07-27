/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** server command
*/

#include "../../my_teams.h"

void launch_server_creation(int i, char **command_tab, homepage_t *general, \
const char *user_id)
{
    char const *nb_of_teams = NULL;
    nb_of_teams = check_nb_of_team();
    if (strcmp(nb_of_teams, "STOP") == 0) {
        printf("Error file_teams\n");
    } else {
        command_tab = my_str_to_word_array(general->client[i].buffer);
        if (fill_team(command_tab, general, nb_of_teams, \
        general->client[i]) == -1) {
            return;
        } else {
            server_team_created(nb_of_teams, \
            general->teams[atoi(nb_of_teams)], user_id);
        }
    }
}

void launch_channel_creation(int i, char **command_tab, homepage_t *general, \
const char *user_id)
{
    command_tab = my_str_to_word_array(general->client[i].buffer);
    general = fill_channel(command_tab, general, \
    general->client[i].current_uuid_team);
    server_channel_created(general->teams[general->client[i].\
    current_uuid_team].channel, general->client[i].current_uuid_team, \
    general->teams[general->client[i].current_uuid_team].name, user_id);
}