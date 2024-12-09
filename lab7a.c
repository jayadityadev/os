#include <stdio.h>

int nof, nor, flag = 0, ref[50], frm[50], pf = 0, victim = -1;
int recent[10], lrucal[50], count = 0;
int lruvictim();

void main() {
	printf("LRU Page Replacement Algorithm:\n");
	printf("\nEnter the number of frames: ");
	scanf("%d", &nof);
	printf("Enter the number of reference string: ");
	scanf("%d", &nor);
	printf("Enter the reference string: ");
	for (int i = 0; i < nor; i++) scanf("%d", &ref[i]);
	printf("\nGiven reference string: ");
	for (int i = 0; i < nor; i++) printf("%4d", ref[i]);
	for (int i = 1;
}
