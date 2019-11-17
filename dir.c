#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

void printDirectory(char path[200]) {
  int size = 0;
    DIR *directory = opendir(path);
    struct dirent *currentFile = readdir(directory);
    struct stat file;
    // printf("Statistic for directory: %s\n", path);
    for (; currentFile !=NULL; currentFile = readdir(directory), stat(currentFile->d_name, &file)) {
        size += (file.st_size);
    }
    rewinddir(directory);
    currentFile = readdir(directory);
    printf("Directories:\n");
    for (; currentFile !=NULL; currentFile = readdir(directory)) {
        // printf("%d \n", currentFile ->d_type);
        if (currentFile->d_type == DT_DIR) {
            printf("\t %s \n", currentFile->d_name);
        }
    }
    printf("Regular files: \n");
    rewinddir(directory);
    currentFile = readdir(directory);
    for (; currentFile !=NULL; currentFile = readdir(directory)) {
        // ("%d \n", currentFile ->d_type);
        if (currentFile->d_type == DT_REG) {
            printf("\t %s \n", currentFile->d_name);
        }
    }
    printf("\nTotal Directory Size: %d Bytes \n", size);
}
