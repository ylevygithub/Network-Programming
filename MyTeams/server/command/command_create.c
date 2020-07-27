/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** server command
*/

#include "../../my_teams.h"

void function_create(homepage_t *general, int i, const char *user_id)
{
    char **command_tab = NULL;

    if (strncmp(general->client[i].buffer, "/create", 7) == 0 \
    && general->client[i].current_uuid_team == 0) {
        launch_server_creation(i, command_tab, general, user_id);
    }
    if (strncmp(general->client[i].buffer, "/create", 7) == 0 \
    && general->client[i].current_uuid_team != 0 && \
    general->client[i].current_channel == 0) {
        launch_channel_creation(i, command_tab, general, user_id);
    }
}

int server_team_created(char const *team_id, teams_t team, \
char const *user_id)
{
    FILE *fptr_add;
    fptr_add = fopen("save/list_teams.txt", "a");

    if (fptr_add == NULL) {
        printf("Error file_client\n");
        return (-1);
    }
    if (analyse_team_name(team, fptr_add, atoi(user_id), team_id) == 0) {
        send(atoi(user_id), "This team has been created", 27, 0);
        server_event_team_created(team_id, team.name, user_id);
    }
    return (0);
}

int server_user_created(char const *user_id, char const *user_name)
{
    FILE *fptr_add;
    FILE *fptr_read;
    fptr_add = fopen("save/list_client.txt", "a");
    fptr_read = fopen("save/list_client.txt", "r");

    if (fptr_add == NULL) {
        printf("Error file_client\n");
        return (-1);
    }
    if (analyse_user_name(user_name, fptr_read, fptr_add, atoi(user_id)) == 0) {
        send(atoi(user_id), "The user has been created", 26, 0);
        server_event_user_created(user_id, user_name);
    }
    return (0);
}

void server_channel_created(channel_t *channel, int team_uuid, \
char *team_name, char const *user_id)
{
    struct stat st = {0};
    char *foldername;
    foldername = create_folder_of_channel(team_name, channel);
    char const team_id[3];
    char const channel_id[3];

    if (stat(foldername, &st) == -1 && strlen(channel[channel->nb_channel]\
    .name) > MAX_NAME_LENGTH) {
        mkdir(foldername, 0700);
        add_description_channel(channel[channel->nb_channel], team_name, \
        team_uuid);
        sprintf(team_id, "%d", team_uuid);
        sprintf(channel_id, "%d", channel->nb_channel);
        send(atoi(user_id), "This channel has been created\n", 31, 0);
        server_event_channel_created(team_id, channel_id, \
        channel[channel->nb_channel].name);
        channel->nb_channel++;
    } else
        send(atoi(user_id), "This channel already exist\n", 28, 0);
}
