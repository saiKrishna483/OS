#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
    int fd, n;
    char buf[1024];
    DIR *dir;
    struct dirent *ent;
    struct stat st;

    // fcntl
    fd = open("file.txt", O_RDONLY);
    fcntl(fd, F_SETFL, O_NONBLOCK);

    // seek
    lseek(fd, 0, SEEK_SET);

    // stat
    stat("file.txt", &st);
    printf("File size: %ld bytes\n", st.st_size);

    // opendir and readdir
    dir = opendir(".");
    while ((ent = readdir(dir)) != NULL) {
        printf("%s\n", ent->d_name);
    }
    closedir(dir);

    return 0;
}

