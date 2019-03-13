#include <stdio.h>
#include <stdlib.h>
#define _POSIX_SOURCE
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (argc == 2) {
            execlp(argv[1], argv[1], NULL);
        } else if (argc >= 3) {
            char **cmd;
            for (int i = 1; i < argc; i++) {
                cmd[i - 1] = argv[i];
            }
            cmd[argc] = NULL;
            execvp(cmd[0], cmd);
        } else {
            cout << "Enter Argument!" << endl;
            exit(EXIT_FAILURE);
        }
        _exit(EXIT_SUCCESS);
    } else {
        int status;
        (void)waitpid(pid, &status, 0);
    }
    return EXIT_SUCCESS;
}