#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, seek_time = 0, max, temp, queue[20], direction;
    float avg_seek_time;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the request queue: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    printf("Enter the direction of head movement (0 for left, 1 for right): ");
    scanf("%d", &direction);
    queue[n] = head;
    n++;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    max = queue[n - 1];
    for (i = 0; i < n; i++) {
        if (head == queue[i]) {
            j = i;
            break;
        }
    }
    if (direction == 1) {
        for (i = j; i < n; i++) {
            seek_time += abs(head - queue[i]);
            head = queue[i];
        }
        seek_time += abs(head - max);
        head = max;
        seek_time += head;
        for (i = 0; i < j; i++) {
            seek_time += abs(head - queue[i]);
            head = queue[i];
        }
    } else {
        for (i = j - 1; i >= 0; i--) {
            seek_time += abs(head - queue[i]);
            head = queue[i];
        }
        seek_time += abs(head - 0);
        head = 0;
        seek_time += head;
        for (i = n - 1; i >= j; i--) {
            seek_time += abs(head - queue[i]);
            head = queue[i];
        }
    }
    avg_seek_time = (float)seek_time / n;
    printf("Total seek time: %d\n", seek_time);
    printf("Average seek time: %.2f\n", avg_seek_time);
    return 0;
}

