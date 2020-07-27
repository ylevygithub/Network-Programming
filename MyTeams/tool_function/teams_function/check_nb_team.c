/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** server command
*/

#include "../../my_teams.h"

char const *check_nb_of_team(void)
{
    char const *team_id = malloc(sizeof(char) * 4 + 1);
    FILE *fptr;
    int chr;
    int count_lines = 0;

    fptr = fopen("save/list_teams.txt", "r");
    if (fptr == NULL)
        return ("STOP");
    chr = getc(fptr);
    while (chr != EOF) {
        if (chr == '\n') {
            count_lines = count_lines + 1;
        }
        chr = getc(fptr);
    }
    fclose(fptr);
    sprintf(team_id, "%d", count_lines);
    return (team_id);
}