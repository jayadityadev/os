#include <stdio.h>

int main() {
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];

    printf("\nMemory Management Scheme - Best Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block no. %d: ", i);
        scanf("%d", &b[i]);
    }
    printf("\nEnter the size of the processes:\n");
    for (i = 1; i <= np; i++) {
        printf("Process no. %d: ", i);
        scanf("%d", &p[i]);
    }
    for (i = 1; i <= np; i++) {
        for (j = 1; j <= nb; j++) {
            if (barray[j] != 1) { // Block not yet allocated
                temp = b[j] - p[i];
                if (temp >= 0 && lowest > temp) { // Best fit condition
                    parray[i] = j;
                    lowest = temp;
                }
            }
        }
        fragment[i] = lowest;
        barray[parray[i]] = 1; // Mark block as allocated
        lowest = 9999;
    }
    // Output section aligned with Code 1's style
    printf("\nProcess Number\tProcess Size\tBlock Number\tBlock Size\tFragment\n");
    for (i = 1; i <= np; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i], parray[i], b[parray[i]], fragment[i]);
    }

    return 0;
}
