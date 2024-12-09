#include<stdio.h>

int i, j, nof, nor, ref[50], frm[10], front = 0, pf = 0, count = 0;

void main() {
    printf("FIFO Page Replacement Algorithm\n");
    printf("Enter number of frames: ");
    scanf("%d", &nof);
    printf("Enter number of references: ");
    scanf("%d", &nor);
    printf("Enter the reference string: ");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);

    for (i = 0; i < nof; i++)
        frm[i] = -1;

    printf("\nRef. String\tPage Frames\n");

    for (i = 0; i < nor; i++) {
        int flag = 0;
        printf("%d\t\t", ref[i]);

        // Check if the page is already in the frame
        for (j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) { // Page fault occurs
            frm[front] = ref[i];
            front = (front + 1) % nof; // Move to the next frame in a circular manner
            pf++;
        }

        for (j = 0; j < nof; j++)
            (frm[j] == -1) ? printf("- ") : printf("%d ", frm[j]);

        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pf);
}
