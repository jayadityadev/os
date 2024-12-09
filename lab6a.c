#include <stdio.h>

int main() {
    int fragments[10], blocks[10], files[10];
    int m, n, number_of_blocks, number_of_files, temp, top = 0;
    static int block_arr[10], file_arr[10];

    printf("\nMemory Management Scheme - Worst Fit\n");
    printf("Enter the total number of blocks: ");
    scanf("%d", &number_of_blocks);
    printf("Enter the total number of files: ");
    scanf("%d", &number_of_files);
    printf("\nEnter the size of the blocks:\n");
    for (m = 1; m <= number_of_blocks; m++) {
        printf("Block No. %d: ", m);
        scanf("%d", &blocks[m]);
    }
    printf("\nEnter the size of the files:\n");
    for (m = 1; m <= number_of_files; m++) {
        printf("File No. %d: ", m);
        scanf("%d", &files[m]);
    }
    for (m = 1; m <= number_of_files; m++) {
        for (n = 1; n <= number_of_blocks; n++) {
            if (block_arr[n] != 1) {
                temp = blocks[n] - files[m];
                if (temp >= 0) {
                    if (top < temp) {
                        file_arr[m] = n;
                        top = temp;
                    }
                }
            }
        }
        fragments[m] = top;
        block_arr[file_arr[m]] = 1;
        top = 0;
    }
    printf("\nFile Number\tFile Size\tBlock Number\tBlock Size\tFragment\n");
    for (m = 1; m <= number_of_files; m++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", m, files[m], file_arr[m], blocks[file_arr[m]], fragments[m]);
    }

    return 0;
}
