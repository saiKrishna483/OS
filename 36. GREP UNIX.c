#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *newline;
    int count = 0, occ = 0;

    if (argc != 3) {
        printf("Usage: %s <filename> <pattern>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        count++;
        if ((newline = strchr(line, '\\n')) != NULL) {
            *newline = '\\0';
        }
        if (strstr(line, argv[2]) != NULL) {
            printf("%s %d %s\n", argv[1], count, line);
            occ++;
        }
    }

    printf("\nOccurrence = %d\n", occ);

    fclose(fp);
    return 0;
}
