#include "step1.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <stddef.h>

struct data_s
{
    fd_set input_fd;
    fd_set output_fd;
    char *input_buf;
    char *output_buf;
};
typedef struct data_s data_t;

int main(void) {
  // disable printf buffering for stdout.
  // do not remove please.
    data_t data;
    fd_set read_fds;
    fd_set write_fds;
    fd_set except_fds;
    int chek = setvbuf(stdout, NULL, _IONBF, 0);

    char buffer[MAX_COMMAND_LENGTH + 1] = {0};
    data.input_buf = buffer;
    data.output_buf = buffer;
    int status = 0;
    int status1 = 0;
    do {
        memset(data.input_buf, 0, MAX_COMMAND_LENGTH);
        memset(data.output_buf, 0, MAX_COMMAND_LENGTH);
        status = read(0, data.input_buf, MAX_COMMAND_LENGTH);
        status1 = write(1, data.output_buf, MAX_COMMAND_LENGTH);
        FD_ZERO(&read_fds);
        FD_ZERO(&write_fds);
        FD_ZERO(&except_fds);
        FD_SET(1, &write_fds);
        if (status == -1) {
            perror("read()");
            return EPI_EXIT_FAILURE;
        }
        else if (chek == -1) {
            perror("setvbuf()");
            return EPI_EXIT_FAILURE;
        }
        else if (status1 == -1) {
            perror("write()");
            return EPI_EXIT_FAILURE;
        }
        else {
            if (on_command(data.input_buf) == false)
                return EPI_EXIT_FAILURE;
        }
    } while (status && status1 && select(4, &read_fds, &write_fds, &except_fds, NULL) != -1);
    return EPI_EXIT_SUCCESS;
}

/*
Finally try to create a server that do the same thing as the step 2 but with sockets.
This server must be able to handle multiple clients at the same time (without fork).
This time, if the in_buffer is full close the connection with the client and display an error on stderror.

Allocate all the resource needed by the client at it connection.

Remember about nc (man nc)
*/