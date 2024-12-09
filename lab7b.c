#include<stdio.h>

int i, j, nof, nor, ref[50], frm[10], recent[50], pf = 0, victim = -1, count = 0;
int lruvictim();

void main() {
    printf("LRU Page Replacement Algorithm\n");
    printf("Enter number of frames: ");
    scanf("%d", &nof);
    printf("Enter number of references: ");
    scanf("%d", &nor);
    printf("Enter the reference string: ");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);

    for (i = 0; i < nof; i++)
        frm[i] = -1;

    for (i = 0; i < 50; i++)
	    recent[i] = -1;

    // printf("\nReference String: ");
    printf("\nRef. String\tPage Frames\n");

    for (i = 0; i < nor; i++) {
        int flag = 0;
        printf("%d\t\t", ref[i]);
        for (j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            count++;
            if (count <= nof)
                victim++;
            else
                victim = lruvictim();

            frm[victim] = ref[i];
            pf++;
        }

        for (j = 0; j < nof; j++)
            (frm[j] == -1) ? printf("- ") : printf("%d ", frm[j]);
        recent[ref[i]] = i;
    }

    printf("\nTotal Page Faults: %d\n", pf);
}

int lruvictim() {
    int least_recent = recent[frm[0]], victim_index = 0;
    for (j = 1; j < nof; j++) {
        if (recent[frm[j]] < least_recent) {
            least_recent = recent[frm[j]];
            victim_index = j;
        }
    }
    return victim_index;
}
