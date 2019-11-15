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
    printf("Statistic for directory: %s\n", path);
    for (; currentFile !=NULL; currentFile = readdir(directory), stat(currentFile->d_name, &file)) {
        size += (file.st_size);
    }
    rewinddir(directory);
    printf("Directories:\n \t");
    for (; currentFile !=NULL; currentFile = readdir(directory), stat(currentFile->d_name, &file)) {
        if (S_ISDIR(file)) {
            printf("%s \n", currentFile->d_name);
        }
    }
    printf("Regular files: \n \t");
    rewinddir(directory);
    for (; currentFile !=NULL; currentFile = readdir(directory), stat(currentFile->d_name, &file)) {
        if (S_ISDIR(file)) {
            printf("%s \n", currentFile->d_name);
        }
    }
    printf("Total Directory Size: %d Bytes \n", size);
}
