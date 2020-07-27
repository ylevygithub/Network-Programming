/*
** EPITECH PROJECT, 2020
** myftp
** File description:
** my header file
*/

#ifndef MY_H
#define MY_H

#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <errno.h>

/****************msgServer1.c***************/
void msg150(int sc);
void msg200(int sc);
void msg214(int sc);
void msg220(int sc);
void msg221(int sc);
/****************msgServer2.c***************/
void msg225(int sc);
void msg226(int sc);
void msg227(int sc);
void msg230(int sc);
void msg250(int sc);
/****************msgServer3.c***************/
void msg331(int sc);
void msg425(int sc);
void msg500(int sc);
void msg501(int sc);
void msg530(int sc);
/****************msgServer4.c***************/
void msg550(int sc);
/**************str_to_word_tab.c************/
int count_char(char *str, int *x);
int count_word(char *str);
char **str_to_word_tab(char *str, int count);
/**************clean_str.c************/
int end_str(char *str);
char *epure_str(char *str);
/**************server_creation.c************/
int create_serveur(int ac, char **av);
/**************serveur_loop.c************/
void end_execution(int sc, int ss);
void new_client(int sc);
int serveur_loop(int ss);
/**************execution.c************/
void verif_read(int nb_read);
int user_cmd(char *buff, int sc);
int	execute(int sc);
/**************help.c************/
void help(int ac, char **av);
void help_command(int sc);
/**************remove.c************/
int remove_file(int sc, char *buff);
/**************list.c************/
void errno_list(void);
void opendir_fail(DIR *dir);
void client_msg_list(int sc);
void my_list(int sc);
/**************ls.c************/
void errno_ls(void);
void my_ls(int sc);
/**************error.c************/
void my_error(char *str, int ss, int sc);
/**************pwd.c************/
int my_pwd(int sc);
/**************create_socket.c************/
int create_socket(void);

#endif
