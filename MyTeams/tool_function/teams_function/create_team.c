/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** server command
*/

#include "../../my_teams.h"

void add_description_team(teams_t team)
{
    FILE *fptr_add_des;
    char *filename = malloc(sizeof(char) * (strlen(team.name) + 21) + 1);
    char *savef = "save/";
    strcpy(filename, savef);
    strcat(filename, team.name);
    strcat(filename, "/");
    strcat(filename, "description.txt");
    fptr_add_des = fopen(filename, "a");
    if (fptr_add_des == NULL) {
        printf("Error in the writting of the description of your team\n");
        fclose(fptr_add_des);
        return;
    }
    fprintf(fptr_add_des, "%s\n", team.description);
    fclose(fptr_add_des);
    free(filename);
}

void create_folder_of_team(char const *team_name)
{
    char *foldername = malloc(sizeof(char) * (strlen(team_name) + 5) + 1);
    char *savef = "save/";
    strcpy(foldername, savef);
    strcat(foldername, team_name);
    mkdir(foldername, 00777);
    free(foldername);
}

int analyse_team_name(teams_t team, FILE *fptr_add, int uuid_client, \
char const *team_id)
{
    FILE *fptr_read;
    fptr_read = fopen("save/list_teams.txt", "r");

    if (strlen(team.name) > MAX_NAME_LENGTH) {
        send(uuid_client, "This team name is too long\n", 28, 0);
        fclose(fptr_read);
        fclose(fptr_add);
        return (-1);
    } else if (find_word_in_file(fptr_read, team.name) == -1) {
        send(uuid_client, "This team name already exist\n", 30, 0);
        fclose(fptr_read);
        fclose(fptr_add);
        return (-1);
    } else {
        fprintf(fptr_add, "%s/%s/%s\n", team.name, team_id, team.description);
        create_folder_of_team(team.name);
        fclose(fptr_add);
        fclose(fptr_read);
        return (0);
    }
}

int fill_team(char **command_client, homepage_t *general, \
char const *nb_of_teams, client_t client)
{
    int nb_arg = nb_arg_of_use(command_client);
    if (nb_arg < 3 || nb_arg > 3) {
        send(client.uuid, "You need to have 2 arguments for using create", \
        46, 0);
        return (-1);
    } else {
        general->teams[atoi(nb_of_teams)].name = malloc(sizeof(char) \
        * strlen(command_client[1]) + 1);
        general->teams[atoi(nb_of_teams)].description = malloc(sizeof(char) \
        * strlen(command_client[2]) + 1);
        general->teams[atoi(nb_of_teams)].description = command_client[2];
        general->teams[atoi(nb_of_teams)].description\
        [(strlen(command_client[2]) + 1)] = '\0';
        general->teams[atoi(nb_of_teams)].name = command_client[1];
        general->teams[atoi(nb_of_teams)].name\
        [(strlen(command_client[1]) + 1)] = '\0';
        return (0);
    }
}