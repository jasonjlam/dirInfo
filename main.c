#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include "dir.h"
#include <errno.h>
// int argc, char *argv[]
int main(int argc, char *argv[]) {
    // Deprecated test for its own directory; comment out if needed
    // printDirectory("./");
    if (argc == 2) {
        printf("%s\n", argv[1]);
        printDirectory(argv[1]);
    }
    else {
        char dir[256];
        printf("Enter a directory:\n");
        fgets(dir, 256, stdin);
        int i = 0;
        for (i; dir[i] != '\0'; i++) {
            if (dir[i] == '\n') {
                dir[i] = '\0';
            }
        }
        printf("%s\n",dir);
        printDirectory(dir);
    }
    return 0;
}
