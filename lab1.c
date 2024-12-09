#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h> // Include for waitpid
#include <unistd.h>   // Include for fork, exec, and getpid

int main() {
    pid_t pid;
    int status;
    
    pid = fork();
    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process, PID = %u\n", getpid());
        execlp("ls", "ls", NULL); // Fixed typo: "Is" -> "ls"
        perror("exec failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        printf("Parent process, PID = %u\n", getpid());
        if (waitpid(pid, &status, 0) == -1) {
            perror("wait failed");
            exit(EXIT_FAILURE);
        }
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child terminated abnormally\n");
        }
        exit(EXIT_SUCCESS);
    }
}
