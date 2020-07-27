/*
** EPITECH PROJECT, 2020
** check_message_serv
** File description:
** check message from the serv
*/

#include "../my_teams.h"

int check_team_create(char *command)
{
    char **cmd_tab = my_str_to_word_array(command);
    char **teams = parsing_user(my_open_read("./save/list_teams.txt"));
    int it = find_user(cmd_tab[1], teams);

    client_event_team_created(take_info(teams[it], 1), 
    take_info(teams[it], 0), take_info(teams[it], 2));
    return (1);
}

int event_user_login(char *command)
{
    char **tab = my_str_to_word_array(command);
    char **user = parsing_user(my_open_read("./save/list_client.txt"));
    int it = find_user(tab[1], user);
    client_event_loggedin(take_info(user[it], 1), tab[1]);

    return (1);
}

int check_recive(char *str, char *command)
{
    if (strcmp(str, "The user has been created") == 0) {
        event_user_login(command);
        return (1);
    }
    if (strcmp(str, "This team has been created") == 0) {
        check_team_create(command);
        return (1);
    }
    return (0);
}