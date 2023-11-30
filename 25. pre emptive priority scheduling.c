#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int remaining_time;
};

int main() {
    int n, i, j, time = 0, total_time = 0, highest_priority = 0, current_process = -1;
    float average_waiting_time = 0, average_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *processes = (struct process *)malloc(n * sizeof(struct process));
    for (i = 0; i < n; i++) {
        printf("Enter the arrival time, burst time and priority of process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        total_time += processes[i].burst_time;
    }
    printf("\nGantt Chart:\n");
    printf("0");
    for (i = 0; i < total_time; i++) {
        highest_priority = -1;
        for (j = 0; j < n; j++) {
            if (processes[j].arrival_time <= i && processes[j].remaining_time > 0) {
                if (highest_priority == -1 || processes[j].priority < processes[highest_priority].priority) {
                    highest_priority = j;
                }
            }
        }
        if (highest_priority == -1) {
            printf("| Idle |%d", i + 1);
        } else {
            if (current_process != processes[highest_priority].pid) {
                printf("| P%d |%d", processes[highest_priority].pid, i);
                current_process = processes[highest_priority].pid;
            }
            processes[highest_priority].remaining_time--;
            if (processes[highest_priority].remaining_time == 0) {
                average_waiting_time += i + 1 - processes[highest_priority].arrival_time - processes[highest_priority].burst_time;
                average_turnaround_time += i + 1 - processes[highest_priority].arrival_time;
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

