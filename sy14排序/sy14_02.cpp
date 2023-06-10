'''
【问题描述】

  利用希尔排序算法，对一组数据进行排序。
【输入形式】

  从键盘输入9个整数

  输入3个值，分别代表3个增量
【输出形式】

  输出每一趟排序的结果。
【样例输入】

  28 13 72 85 39 41 6 20 25

  4   2   1

【样例输出】

  25 13 6 20 28 41 72 85 39

  6 13 25 20 28 41 39 85 72

  6 13 20 25 28 39 41 72 85
【样例说明】
【评分标准】
'''
#include <stdio.h>

void shellSort(int arr[], int n, int increments[], int num_increments) {
    int i, j, temp, increment;

    for (int k = 0; k < num_increments; k++) {
        increment = increments[k];

        for (i = increment; i < n; i++) {
            temp = arr[i];
            j = i;

            while (j >= increment && arr[j - increment] > temp) {
                arr[j] = arr[j - increment];
                j = j - increment;
            }

            arr[j] = temp;
        }

        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int arr[9];
    int increments[3];
    int i;

    // 从键盘输入9个整数
    for (i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
    }

    // 输入3个值，分别代表3个增量
    for (i = 0; i < 3; i++) {
        scanf("%d", &increments[i]);
    }

    shellSort(arr, 9, increments, 3);

    return 0;
}

