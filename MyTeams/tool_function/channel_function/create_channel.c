/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** server command
*/

#include "../../my_teams.h"

void add_description_channel(channel_t channel, char *team_name, int team_id)
{
    FILE *fptr_add_des;
    char *filename = malloc(sizeof(char) * (strlen(team_name)+ 6 +\
    strlen(channel.name)) + 1);
    char *savef = "save/";
    strcpy(filename, savef);
    strcat(filename, team_name);
    strcat(filename, "/");
    strcat(filename, channel.name);
    strcat(filename, "/");
    strcat(filename, "description.txt");
    fptr_add_des = fopen(filename, "a");
    if (fptr_add_des == NULL) {
        printf("Error in the writting of the description of your channel\n");
        fclose(fptr_add_des);
        return;
    }
    fprintf(fptr_add_des, "%s\n", channel.description);
    fclose(fptr_add_des);
    free(filename);
}

homepage_t *fill_channel(char **command_client, homepage_t *general, \
int uuid_team)
{
    general->teams[uuid_team].channel->name = malloc(sizeof(char) \
    * strlen(command_client[1]) + 1);
    general->teams[uuid_team].channel->description = malloc(sizeof(char) \
    * strlen(command_client[2]) + 1);
    general->teams[uuid_team].channel->description = command_client[2];
    general->teams[uuid_team].channel->description\
    [(strlen(command_client[2]) + 1)] = '\0';
    general->teams[uuid_team].channel->name = command_client[1];
    general->teams[uuid_team].channel->name\
    [(strlen(command_client[1]) + 1)] = '\0';
    return (general);
}

char *create_folder_of_channel(char *team_name, channel_t *channel)
{
    char *foldername = malloc(sizeof(char) * (strlen(team_name) + 6 +\
    strlen(channel[channel->nb_channel].name)) + 1);
    char *savef = "save/";
    strcpy(foldername, savef);
    strcat(foldername, team_name);
    strcat(foldername, "/");
    strcat(foldername, channel[channel->nb_channel].name);
    return (foldername);
}