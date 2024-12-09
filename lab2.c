#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int pid, burstTime, waitingTime, turnaroundTime, arrivalTime, priority,
        remainingTime;
} Process;

void FCFS(Process p[], int n);
void SJF(Process p[], int n);
void RoundRobin(Process p[], int n, int quantum);
void PriorityScheduling(Process p[], int n);
void calculateMetrics(Process p[], int n);
void resetTimes(Process p[], int n);

void FCFS(Process p[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        p[i].waitingTime = currentTime;
        currentTime += p[i].burstTime;
        p[i].turnaroundTime = currentTime;
    }
}

void SJF(Process p[], int n) {
    int completed = 0, currentTime = 0, shortest = 0, minm = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; i++) {
        p[i].remainingTime = p[i].burstTime;
    }

    while (completed != n) {
        minm = INT_MAX;
        shortest = -1;
        found = false;

        for (int i = 0; i < n; i++) {
            if (p[i].arrivalTime <= currentTime && p[i].remainingTime < minm &&
                p[i].remainingTime > 0) {
                minm = p[i].remainingTime;
                shortest = i;
                found = true;
            }
        }

        if (!found) {
            currentTime++;
            continue;
        }

        p[shortest].remainingTime--;
        currentTime++;

        if (p[shortest].remainingTime == 0) {
            completed++;
            p[shortest].turnaroundTime = currentTime - p[shortest].arrivalTime;
            p[shortest].waitingTime =
                p[shortest].turnaroundTime - p[shortest].burstTime;
        }
    }
}

void RoundRobin(Process p[], int n, int quantum) {
    int currentTime = 0, completed = 0;
    for (int i = 0; i < n; i++) {
        p[i].remainingTime = p[i].burstTime;
    }

    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remainingTime > 0) {
                if (p[i].remainingTime > quantum) {
                    currentTime += quantum;
                    p[i].remainingTime -= quantum;
                } else {
                    currentTime += p[i].remainingTime;
                    p[i].remainingTime = 0;
                    p[i].turnaroundTime = currentTime - p[i].arrivalTime;
                    p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
                    completed++;
                }
            }
        }
    }
}

void PriorityScheduling(Process p[], int n) {
    int currentTime = 0, completed = 0, highestPriority = -1;

    while (completed != n) {
        int maxPriority = INT_MAX;
        highestPriority = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].arrivalTime <= currentTime && p[i].remainingTime > 0 &&
                p[i].priority < maxPriority) {
                maxPriority = p[i].priority;
                highestPriority = i;
            }
        }

        if (highestPriority != -1) {
            currentTime += p[highestPriority].burstTime;
            p[highestPriority].turnaroundTime =
                currentTime - p[highestPriority].arrivalTime;
            p[highestPriority].waitingTime = p[highestPriority].turnaroundTime -
                                             p[highestPriority].burstTime;
            p[highestPriority].remainingTime = 0;
            completed++;
        } else {
            currentTime++;
        }
    }
}

void calculateMetrics(Process p[], int n) {
    int totalWT = 0, totalTAT = 0;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burstTime,
               p[i].waitingTime, p[i].turnaroundTime);
        totalWT += p[i].waitingTime;
        totalTAT += p[i].turnaroundTime;
    }

    float avgWT = (float)totalWT / n;
    float avgTAT = (float)totalTAT / n;

    printf("Average Waiting Time: %.2f\n", avgWT);
    printf("Average Turnaround Time: %.2f\n", avgTAT);
}

void resetTimes(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].waitingTime = 0;
        p[i].turnaroundTime = 0;
        p[i].remainingTime = p[i].burstTime;
    }
}

int main() {
    int quantum = 4;
    Process proc[] = {{1, 6, 0, 0, 0, 2},
                      {2, 8, 0, 0, 0, 1},
                      {3, 7, 0, 0, 0, 3},
                      {4, 3, 0, 0, 0, 4}};
    int n = sizeof(proc) / sizeof(proc[0]);

    // FCFS Scheduling Algorithm
    printf("\nFirst Come, First Serve Scheduling:\n");
    FCFS(proc, n);
    calculateMetrics(proc, n);
    resetTimes(proc, n);

    // SJF Scheduling Algorithm
    printf("\nShortest Job First Scheduling:\n");
    SJF(proc, n);
    calculateMetrics(proc, n);
    resetTimes(proc, n);

    // Round Robin Scheduling Algorithm
    printf("\nRound Robin Scheduling:\n");
    RoundRobin(proc, n, quantum);
    calculateMetrics(proc, n);
    resetTimes(proc, n);

    // Priority Scheduling
    printf("\nPriority Scheduling:\n");
    PriorityScheduling(proc, n);
    calculateMetrics(proc, n);
    resetTimes(proc, n);

    return 0;
}
