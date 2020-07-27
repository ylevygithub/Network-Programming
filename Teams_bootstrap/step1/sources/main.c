#include "step1.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>

/*
    In this exercise, you should always have the following output for every tests.
    Please complete the main.c file with your own code.
    You can launch a set of tests with ./tests.sh the program will stop if a test fail and display some debug
    information (if stdin is closed stop the program).
    Take a look inside the script you understand what is tested.
    You can also take a look inside on_command.c but do not edit it.
    > ( echo - ne " hello \n"; sleep 0.5; echo - ne " world \n") | ./ bin
    COMMAND : " hello \n \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0 "
    OK : the command seems all right .
    COMMAND : " world \n \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0 "
    OK : the command seems all right .
*/
/*
You need to reset every fd_set before calling select.
You may need a temporary buffer to store the data until you receive a complete command
*/
int main(void) {
  // disable printf buffering for stdout.
  // do not remove please.
    int chek = setvbuf(stdout, NULL, _IONBF, 0);
  /**
   * EXAMPLE CODE WHICH WILL NOT WORK ...
   * PLEASE PATCH IT ;-)
   */
    fd_set rfds;
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    int retval = select(1, &rfds, NULL, NULL, &tv);
    char buffer[MAX_COMMAND_LENGTH + 1] = {0};
    int status = 0;
    do {
        memset(buffer, 0, MAX_COMMAND_LENGTH);
        status = read(0, buffer, MAX_COMMAND_LENGTH);
        FD_ZERO(&rfds);
        FD_SET(status, &rfds);
        if (status == -1) {
            perror("read()");
            return EPI_EXIT_FAILURE;
        }
        else if (retval == -1) {
            perror("select()");
            return EPI_EXIT_FAILURE;
        }
        else if (retval != -1) {
            write(1, &buffer, MAX_COMMAND_LENGTH);
            FD_ISSET(status, &rfds);
        }
        else {
            if (on_command(buffer) == false)
                return EPI_EXIT_FAILURE;
        }
    } while (status && chek == 0 && retval != -1);
    return EPI_EXIT_SUCCESS;
}
/*
Here some examples of data that could be send to on_command please; look at errors that are shown.
{
    char cmd [ MAX_COMMAND_LENGTH + 1] = " hello \n";
    on_command ( cmd ) ;
}
{
    char cmd [ MAX_COMMAND_LENGTH + 1] = " hello ";
    on_command ( cmd ) ;
}
{
    char cmd [ MAX_COMMAND_LENGTH + 1] = " hello \n\n";
    on_command ( cmd ) ;
}
{
    char cmd [ MAX_COMMAND_LENGTH + 1] = " hello \ nhel ";
    on_command ( cmd ) ;
}
{
    char cmd [ MAX_COMMAND_LENGTH + 1] = " hello \n \0\0 hel ";
    on_command ( cmd ) ;
}
*/