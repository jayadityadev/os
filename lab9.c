#include <stdio.h>
#include <stdlib.h>

void main() {
    int f[50], p, i, st, len, j, c, k, a;

    // Initialize all blocks as unallocated
    for (i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter how many blocks already allocated: ");
    scanf("%d", &p);

    printf("Enter blocks already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        if (a >= 0 && a < 50) {
            f[a] = 1;
        } else {
            printf("Invalid block number: %d. Skipping...\n", a);
        }
    }

    while (1) {
        printf("Enter index starting block and length: ");
        scanf("%d%d", &st, &len);
        k = len;

        if (st >= 0 && st < 50) {
            if (f[st] == 0) {
                for (j = st; j < (st + k) && j < 50; j++) {
                    if (f[j] == 0) {
                        f[j] = 1;
                        printf("%d --------> %d\n", j, f[j]);
                    } else {
                        printf("%d Block is already allocated\n", j);
                        k++; // Extend the length to account for the already allocated block
                    }
                }
            } else {
                printf("%d starting block is already allocated\n", st);
            }
        } else {
            printf("Invalid starting block: %d\n", st);
        }

        printf("Do you want to enter more file (Yes - 1 / No - 0): ");
        scanf("%d", &c);
        if (c == 0)
            break;
    }
}
