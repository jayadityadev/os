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
    int fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open FIFO for reading!");
        exit(EXIT_FAILURE);
    }
    while (1) {
        read(fd, buf, BUFSIZE);
        printf("Received: %s", buf);
        if (strncmp(buf, "exit", 4) == 0) {
            break;
        }
    }
    close(fd);
    return 0;
}