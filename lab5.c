#include <stdio.h>
#define MAX_PROCESS 10
#define MAX_RESOURCE 10

int main() {
    int allocation[MAX_PROCESS][MAX_RESOURCE], max[MAX_PROCESS][MAX_RESOURCE],
        need[MAX_PROCESS][MAX_RESOURCE];
    int available[MAX_RESOURCE], work[MAX_RESOURCE], finish[MAX_PROCESS] = {0};
    int safeSeq[MAX_PROCESS];
    int n, m;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the allocation matrix: \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &allocation[i][j]);

    printf("Enter the max matrix: \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%d", &max[i][j]);

    printf("Enter the available resources: ");
    for (int i = 0; i < m; i++) scanf("%d", &available[i]);

    // Calculate need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) need[i][j] = max[i][j] - allocation[i][j];

    // Initialize work as a copy of available resources
    for (int i = 0; i < m; i++) work[i] = available[i];

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) break;
                }
                // If all resources for this process are available
                if (j == m) {
                    // Add allocated resources to work
                    for (int k = 0; k < m; k++) work[k] += allocation[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        // If no process was found in this pass, no safe state exists
        if (!found) {
            printf("System is not in safe state!\n");
            return 0;
        }
    }

    // Print safe sequence if safe state exists
    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++) printf("P%d ", safeSeq[i]);
    printf("\n");
    return 0;
}
