'''
������������

  ����ϣ�������㷨����һ�����ݽ�������
��������ʽ��

  �Ӽ�������9������

  ����3��ֵ���ֱ����3������
�������ʽ��

  ���ÿһ������Ľ����
���������롿

  28 13 72 85 39 41 6 20 25

  4   2   1

�����������

  25 13 6 20 28 41 72 85 39

  6 13 25 20 28 41 39 85 72

  6 13 20 25 28 39 41 72 85
������˵����
�����ֱ�׼��
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

    // �Ӽ�������9������
    for (i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
    }

    // ����3��ֵ���ֱ����3������
    for (i = 0; i < 3; i++) {
        scanf("%d", &increments[i]);
    }

    shellSort(arr, 9, increments, 3);

    return 0;
}

