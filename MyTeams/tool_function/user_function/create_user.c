/*
** EPITECH PROJECT, 2020
** myteams
** File description:
** server command
*/

#include "../../my_teams.h"

int find_word_in_file(FILE *fptr, const char *word)
{
    char str[32];
    char *pos = NULL;
    int line = -1;
    int word_find = 0;

    while ((fgets(str, 32, fptr)) != NULL) {
        line += 1;
        pos = strstr(str, word);

        if (pos != NULL) {
            word_find++;
            return (-1);
        }
    }
    if (word_find == 0)
        return (0);
    return (0);
}

int analyse_user_name(char const *command_tab, FILE *fptr_read, \
FILE *fptr_add, int socket)
{
    if (strlen(command_tab) > MAX_NAME_LENGTH) {
        send(socket, "This user name is too long\n", 28, 0);
        fclose(fptr_read);
        fclose(fptr_add);
        return (-1);
    } else if (find_word_in_file(fptr_read, command_tab) == -1) {
        send(socket, "This user name already exist\n", 30, 0);
        fclose(fptr_read);
        fclose(fptr_add);
        return (-1);
    } else {
        fprintf(fptr_add, "%s/%i\n", command_tab, socket);
        fclose(fptr_add);
        fclose(fptr_read);
        return (0);
    }
}