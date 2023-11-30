#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, seek_time = 0;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("The sequence of head movement is: %d", head);
    for (i = 0; i < n; i++) {
        seek_time += abs(head - requests[i]);
        head = requests[i];
        printf(" -> %d", head);
    }
    printf("\nThe total seek time is: %d\n", seek_time);
    return 0;
}

