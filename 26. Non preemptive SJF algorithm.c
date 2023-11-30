#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int remaining_time;
};

int main() {
    int n, i, j, time = 0, total_time = 0, shortest = -1;
    float average_waiting_time = 0, average_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *processes = (struct process *)malloc(n * sizeof(struct process));
    for (i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        total_time += processes[i].burst_time;
    }
    printf("\nGantt Chart:\n");
    printf("0");
    for (i = 0; i < total_time; i++) {
        shortest = -1;
        for (j = 0; j < n; j++) {
            if (processes[j].arrival_time <= i && processes[j].remaining_time > 0) {
                if (shortest == -1 || processes[j].burst_time < processes[shortest].burst_time) {
                    shortest = j;
                }
            }
        }
        if (shortest == -1) {
            printf("| Idle |%d", i + 1);
        } else {
            printf("| P%d |%d", processes[shortest].pid, i + 1);
            processes[shortest].remaining_time--;
            if (processes[shortest].remaining_time == 0) {
                average_waiting_time += i + 1 - processes[shortest].arrival_time - processes[shortest].burst_time;
                average_turnaround_time += i + 1 - processes[shortest].arrival_time;
            }
        }
    }
    printf("|\n\n");
    average_waiting_time /= n;
    average_turnaround_time /= n;
    printf("Average waiting time: %.2f\n", average_waiting_time);
    printf("Average turnaround time: %.2f\n", average_turnaround_time);
    free(processes);
    return 0;
}

