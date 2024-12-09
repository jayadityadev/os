#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void main() {
    int buffer[MAX], bufsize, in, out, produce, consume, choice = 0;
    in = 0;
    out = 0;
    bufsize = MAX + 1;
    while (choice != 3) {
        printf("1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if ((in + 1) % bufsize == out)
                    printf("Buffer is full!\n");
                else {
                    printf("Enter the value: ");
                    scanf("%d", &produce);
                    buffer[in] = produce;
                    in = (in + 1) % bufsize;
                }
                break;
            case 2:
                if (in == out)
                    printf("Buffer is empty!\n");
                else {
                    consume = buffer[out];
                    printf("The consumed value is: %d\n", consume);
                    out = (out + 1) % bufsize;
                }
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}