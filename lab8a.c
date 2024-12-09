#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct {
    char dname[10], fname[10][10];
    int fcnt;
} dir;

void main() {
    int i, ch;
    char f[30];
    dir.fcnt = 0;

    printf("Enter the name of the directory: ");
    scanf("%s", dir.dname);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display Files\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the file name: ");
                scanf("%s", dir.fname[dir.fcnt]);
                dir.fcnt++;
                printf("File created successfully.\n");
                break;

            case 2:
                printf("Enter the file name: ");
                scanf("%s", f);
                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(f, dir.fname[i]) == 0) {
                        printf("File %s is deleted.\n", f);
                        strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                        dir.fcnt--;
                        break;
                    }
                }
                if (i == dir.fcnt)
                    printf("File %s not found.\n", f);
                break;

            case 3:
                printf("Enter the file name: ");
                scanf("%s", f);
                for (i = 0; i < dir.fcnt; i++) {
                    if (strcmp(f, dir.fname[i]) == 0) {
                        printf("File %s is found.\n", f);
                        break;
                    }
                }
                if (i == dir.fcnt)
                    printf("File %s not found.\n", f);
                break;

            case 4:
                if (dir.fcnt == 0)
                    printf("Directory is empty.\n");
                else {
                    printf("The files in the directory are:\n");
                    for (i = 0; i < dir.fcnt; i++)
                        printf("\t%s\n", dir.fname[i]);
                }
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
