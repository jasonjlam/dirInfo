#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <dirent.h>

void printDirectory(char path[200]) {
  int size = 0;
    DIR *directory = opendir(path);
    struct dirent *currentFile = readdir(directory);
    // Checking if the directory can be opened or not
    if (currentFile == NULL) {
        printf("Error opening directory: errno %d", errno);
        return;
    }
    // Sums up the sizes
    struct stat file;
    // printf("Statistic for directory: %s\n", path);
    for (; currentFile !=NULL; currentFile = readdir(directory), stat(currentFile->d_name, &file)) {
        // printf("%ld \n", file.st_size);
        size += (file.st_size);
    }
    // Checks all subdirectories (recursive implementation to be done later)
    rewinddir(directory);
    printf("Directories:\n");
    for (currentFile = readdir(directory); currentFile !=NULL; currentFile = readdir(directory)) {
        // printf("%d \n", currentFile ->d_type);
        if (currentFile->d_type == DT_DIR) {
            printf("\t %s \n", currentFile->d_name);
        }
    }
    // Now checks for files
    printf("Regular files: \n");
    rewinddir(directory);
    for (currentFile = readdir(directory); currentFile !=NULL; currentFile = readdir(directory)) {
        // ("%d \n", currentFile ->d_type);
        if (currentFile->d_type == DT_REG) {
            printf("\t %s\n", currentFile->d_name);
        }
    }
    closedir(directory);
    printf("\nTotal Directory Size: %d Bytes \n", size);
}
