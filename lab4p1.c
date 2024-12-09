#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define FIFO_NAME "myfifo"
#define BUFSIZE 100

int main() {
    char buf[BUFSIZE];
    mkfifo(FIFO_NAME, 0666);
    int fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open FIFO for writing!");
        exit(EXIT_FAILURE);
    }
    while (1) {
        printf("Enter a message ('exit' to quit): ");
        fgets(buf, BUFSIZE, stdin);
        write(fd, buf, BUFSIZE);
        if (strncmp(buf, "exit", 4) == 0) {
            break;
        }
    }
    close(fd);
    return 0;
}