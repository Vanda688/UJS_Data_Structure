'''
二路归并排序主要使用了分治算法，将一个规模大的问题，分解成n个较小规模而结构相似的子问题。这些子问题都解决方法都是类似的，当这些子问题都解决之后，归并子问题的结果，就得到了大问题的解。二路归并排序的算法主旨是“分解”和“归并”。

分解：

将一个数组分成两个小组，对每个小组分别进行排序。对每个小组分别排序时，采用继续分成两个小组，直到划分出来的小组只有一个元素，一个元素即为有序集合。

归并：

将两两有序数组合并成一个大的数组，重复这个过程

【样例输入】 6 3 2 1 8 9 10 4 -1  //以-1 作为

【样例输出】

 trip1：3 6 1 2 8 9 4 10  // (6)(3) 有序归并 (2)(1) 有序归并(8)(9) 有序归并 (4)(10)有序归并

 trip2：1 2 3 6 4 8 9 10  //(3 6)(1 2） 有序归并    （8 9）（4 10）有序归并

 trip3：1 2 3 4 6 8 9 10  //(1 2 3 6 )(4 8 9 10) 有序归并

1 2 3 4 6 8 9 10  //输出排好序的序列
'''
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




