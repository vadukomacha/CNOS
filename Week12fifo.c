#include <stdio.h>
int main()
{
    int frames[10], pages[20];
    int frame_count, page_count;
    int i, j, k = 0;
    int page_faults = 0;
    int found;
    printf("Enter number of frames: ");
    scanf("%d", &frame_count);
    printf("Enter number of pages: ");
    scanf("%d", &page_count);
    printf("Enter page reference string:\n");
    for (i = 0; i < page_count; i++)
        scanf("%d", &pages[i]);
    for (i = 0; i < frame_count; i++)
        frames[i] = -1;
    for (i = 0; i < page_count; i++)
    {
        found = 0;
        for (j = 0; j < frame_count; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            frames[k] = pages[i];
            k = (k + 1) % frame_count;
            page_faults++;
        }
    }
    printf("Total Page Faults = %d\n", page_faults);
    return 0;
}