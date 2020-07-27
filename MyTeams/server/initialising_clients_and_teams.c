/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** initialise all the clients before the big loop
*/

#include "../my_teams.h"

client_t *initialise_all_clients(homepage_t *list_client)
{
    list_client->client = malloc(sizeof(client_t) * 40 + 1);
    list_client->max_clients = 40;
    for (int i = 0; i < list_client->max_clients; i++) {
        list_client->client[i].uuid = 0;
        list_client->client[i].nb_team = 0;
        list_client->client[i].uuid_team = malloc(sizeof(int) * 20 + 1);
        list_client->client[i].current_uuid_team = 0;
    }
    return (list_client->client);
}

teams_t *initialise_all_teams(homepage_t *list_teams)
{
    list_teams->teams = malloc(sizeof(teams_t) * 20 + 1);
    list_teams->max_teams = 20;
    for (int i = 0; i < list_teams->max_teams; i++)
        list_teams->teams[i].uuid = i;
    return (list_teams->teams);
}

homepage_t *initialise_all_clients_and_teams(homepage_t *general)
{
    general->client = initialise_all_clients(general);
    general->teams = initialise_all_teams(general);
    return (general);
}