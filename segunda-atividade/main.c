#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    for (int i = 0; i < n; i++) {
        if (fork() == 0) {
            execl("./hello", "hello", NULL);
            exit(1);
        }
    }

    for (int i = 0; i < n; i++) {
        wait(NULL);
    }
    
    return 0;
}
