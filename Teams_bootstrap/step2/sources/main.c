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
Compile this main and start it with strace.
#include <sys/select.h>
#include <stddef.h>

int main(void) {
    fd_set read_fds;
    fd_set write_fds;
    fd_set except_fds;
    do {
        FD_ZERO(&read_fds);
        FD_ZERO(&write_fds);
        FD_ZERO(&except_fds);
        FD_SET(1, &write_fds);
    } while (select(4, &read_fds, &write_fds, &except_fds, NULL) != -1);
}

If you need more information about the fds look at man 2 strace, and find the flag --decode-fds=set.
As you can see something interesting append !
The select never stop unlocking. . . which is not really nice for our cpu and battery consumption (#GreenCode)
This is because the fd 2 (stdout) is most of the time ready to be write to.
From now on try to create a program that read when needed from stdin and when a line break is detected
(or the command buffer is full) write the content of the command (only the command not all the buffer)
in UPPER case on stdout.
Please remember to check if the fd is ready to be read or write before calling read or write.

Create a datatype that contain:
- an input fd.
- an output fd.
- one buffer for input.
- one buffer for output.
*/