#include <stdio.h>

int request[50];
int SIZE;
int pre;
int head;
int uptrack;
int downtrack;

struct max {
    int up;
    int down;
} kate[50];

int dist(int a, int b) {
    if (a > b)
        return a - b;
    return b - a;
}

void sort(int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (request[j] > request[j + 1]) {
                int temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }
    j = 0;
    i = 0;
    while (request[i] != head) {
        kate[j].down = request[i];
        j++;
        i++;
    }
    downtrack = j;
    i++;
    j = 0;
    while (i < n) {
        kate[j].up = request[i];
        j++;
        i++;
    }
    uptrack = j;
}

void scan(int n) {
    int i;
    int seekcount = 0;
    printf("Seek Sequence: ");
    sort(n);
    if (pre < head) {
        for (i = 0; i < uptrack; i++) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].up);
            head = kate[i].up;
        }
        for (i = downtrack - 1; i > 0; i--) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].down);
            head = kate[i].down;
        }
    } else {
        for (i = downtrack - 1; i >= 0; i--) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].down);
            head = kate[i].down;
        }
        for (i = 0; i < uptrack - 1; i++) {
            printf("%d ", head);
            seekcount += dist(head, kate[i].up);
            head = kate[i].up;
        }
    }
    printf("%d\n", head);
    printf("Total Distance: %d\n", seekcount);
}

int main() {
    int n, i;
    printf("Enter the disk size: ");
    scanf("%d", &SIZE);
    printf("Enter the number of request sequences: ");
    scanf("%d", &n);
    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);
    printf("Enter the current head position: ");
    scanf("%d", &head);
    request[n] = head;
    request[n + 1] = SIZE - 1;
    request[n + 2] = 0;
    printf("Enter the previous request position: ");
    scanf("%d", &pre);
    scan(n + 3);
    return 0;
}