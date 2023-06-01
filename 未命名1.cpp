#include <stdio.h>
#include <stdlib.h>
void mergeSort(int *array, int len);
int *readInput(int *len)
{
    int *array = NULL;
    int x, i = 0, size = 10, capacity = size;

    array = (int *)malloc(capacity * sizeof(int));

    scanf("%d", &x);
    while (x != -1)
    {
        if (i >= capacity)
        {
            capacity *= 2;
            array = (int *)realloc(array, capacity * sizeof(int));
        }
        array[i++] = x;
        scanf("%d", &x);
    }
    *len = i;
    return array;
}

void merge(int *array, int leftStart, int leftEnd, int rightStart, int rightEnd)
{
    int *sortedArray = (int *)calloc(rightEnd - leftStart + 1, sizeof(int));
    int i = leftStart, j = rightStart, k = 0;

    while (i <= leftEnd && j <= rightEnd)
    {
        if (array[i] < array[j])
        {
            sortedArray[k++] = array[i++];
        }
        else
        {
            sortedArray[k++] = array[j++];
        }
    }

    while (i <= leftEnd)
    {
        sortedArray[k++] = array[i++];
    }
    while (j <= rightEnd)
    {
        sortedArray[k++] = array[j++];
    }

    for (i = leftStart, k = 0; i <= rightEnd; i++, k++)
    {
        array[i] = sortedArray[k];
    }

    free(sortedArray);
}

void mergeSort(int *array, int len)
{
    if (len <= 1)
        return;

    int i, leftStart, leftEnd, rightStart, rightEnd, trip = 1;

    for (i = 1; i < len; i *= 2, trip++)
    {
        for (leftStart = 0; leftStart < len - i; leftStart = rightEnd + 1)
        {
            leftEnd = leftStart + i - 1;
            rightStart = leftEnd + 1;
            rightEnd = rightStart + i - 1;

            if (rightEnd >= len)
            {
                rightEnd = len - 1;
            }

            merge(array, leftStart, leftEnd, rightStart, rightEnd);
        }
        printf("trip%d:", trip);
        for (int k = 0; k < len; k++)
            printf("%d ", array[k]);
        printf("\n");
    }
}

int main()
{
    int len;
    int *a = readInput(&len);

    mergeSort(a, len);

    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);
    printf("\n");

    free(a);
    return 0;
}

