#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, size, i;
    int free_blocks[100];
    for (i = 0; i < 100; i++)
        free_blocks[i] = 0;

    printf("Enter number of files: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter size of file %d: ", i + 1);
        scanf("%d", &size);
        int index_block = -1;
        int j;

        for (j = 0; j < 100; j++)
        {
            if (free_blocks[j] == 0)
            {
                index_block = j;
                free_blocks[j] = 1;
                break;
            }
        }
        if (index_block == -1)
        {
            printf("No free block for index\n");
            continue;
        }
        int *blocks = (int *)malloc(size * sizeof(int));
        int count = 0;
        for (j = 0; j < 100 && count < size; j++)
        {
            if (free_blocks[j] == 0)
            {
                blocks[count] = j;
                free_blocks[j] = 1;
                count++;
            }
        }
        if (count < size)
        {
            printf("Not enough free blocks\n");
            free(blocks);
            continue;
        }
        printf("File %d allocated. Index block: %d, Data blocks: ", i + 1, index_block);
        for (j = 0; j < size; j++)
            printf("%d ", blocks[j]);
        printf("\n");
        free(blocks);
    }
    return 0;
}