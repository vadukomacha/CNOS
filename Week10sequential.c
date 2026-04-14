#include <stdio.h>
int main()
{
    int n, start, size, i;
    printf("Enter number of files: ");
    scanf("%d", &n);
    int allocated[100] = {0};
    for (i = 0; i < n; i++)
    {
        printf("Enter start block and size of file %d: ", i + 1);
        scanf("%d %d", &start, &size);
        int j, flag = 0;
        for (j = start; j < start + size; j++)
        {
            if (allocated[j] == 1)
            {
                printf("Block %d already allocated. Cannot allocate file %d\n", j, i + 1);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (j = start; j < start + size; j++)
                allocated[j] = 1;
            printf("File %d allocated from block %d to %d\n", i + 1, start, start + size - 1);
        }
    }
    return 0;
}