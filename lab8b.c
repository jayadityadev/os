#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct {
    char dname[10], fname[10][10];
    int fcnt;
} dir[10];

void main() {
    int i, ch, dcnt, k;
    char f[30], d[30];
    dcnt = 0;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Directory\n");
        printf("2. Create File\n");
        printf("3. Delete File\n");
        printf("4. Search File\n");
        printf("5. Display Files\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the name of the directory: ");
                scanf("%s", dir[dcnt].dname);
                dir[dcnt].fcnt = 0;
                dcnt++;
                printf("Directory '%s' created successfully.\n", dir[dcnt - 1].dname);
                break;

            case 2:
                printf("Enter the name of the directory: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter the name of the file to create: ");
                        scanf("%s", dir[i].fname[dir[i].fcnt]);
                        dir[i].fcnt++;
                        printf("File '%s' created successfully in directory '%s'.\n", dir[i].fname[dir[i].fcnt - 1], d);
                        break;
                    }
                }
                if (i == dcnt)
                    printf("Directory '%s' not found.\n", d);
                break;

            case 3:
                printf("Enter the name of the directory: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter the name of the file to delete: ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                printf("File '%s' deleted successfully from directory '%s'.\n", f, d);
                                dir[i].fcnt--;
                                strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]);
                                goto end_delete;
                            }
                        }
                        printf("File '%s' not found in directory '%s'.\n", f, d);
                        goto end_delete;
                    }
                }
                printf("Directory '%s' not found.\n", d);
                end_delete: break;

            case 4:
                printf("Enter the name of the directory: ");
                scanf("%s", d);
                for (i = 0; i < dcnt; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("Enter the name of the file to search: ");
                        scanf("%s", f);
                        for (k = 0; k < dir[i].fcnt; k++) {
                            if (strcmp(f, dir[i].fname[k]) == 0) {
                                printf("File '%s' found in directory '%s'.\n", f, d);
                                goto end_search;
                            }
                        }
                        printf("File '%s' not found in directory '%s'.\n", f, d);
                        goto end_search;
                    }
                }
                printf("Directory '%s' not found.\n", d);
                end_search: break;

            case 5:
                if (dcnt == 0)
                    printf("No directories available.\n");
                else {
                    printf("Directories and their files:\n");
                    for (i = 0; i < dcnt; i++) {
                        printf("Directory '%s':\n", dir[i].dname);
                        if (dir[i].fcnt == 0) {
                            printf("\tNo files.\n");
                        } else {
                            for (k = 0; k < dir[i].fcnt; k++) {
                                printf("\t%s\n", dir[i].fname[k]);
                            }
                        }
                    }
                }
                break;

            case 6:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
