#include <stdio.h>
int main() {
    int indexBlock, n, blocks[20];
    printf("Enter index block number: ");
    scanf("%d", &indexBlock);
    printf("Enter no. of blocks for the file: ");
    scanf("%d", &n);
    printf("Enter block numbers: ");
    for(int i=0; i<n; i++) scanf("%d", &blocks[i]);

    printf("\nIndex Block: %d", indexBlock);
    printf("\nFile contains: ");
    for(int i=0; i<n; i++) printf("%d -> %d\n", indexBlock, blocks[i]);
    return 0;
}