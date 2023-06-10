'''
����Ŀ��

���ڹ�˾Ա�����ܾ�ѡ��ʤ����CS COMPANY�ܾ���Ms.Z ����ã�������ÿλԱ�������𡣹�˾������ÿ���˱�����ڹ�˾�Ĺ���Ϊ��׼���������ǵõ��Ľ�����١�

���ǣ�Ms.Z�ٿ�m����̸��ÿλ�μӻ�̸�Ĵ�������Լ��������������ΪԱ��a�Ľ���Ӧ�ñ�b�ߣ���Mr.Z ����Ҫ�ҳ�һ�ֽ��𷽰��������λ��������������ͬʱʹ���ܽ��������١�ÿλԱ������Ϊ���������100Ԫ��

����ʾ��������������������Ӧ�ã����ȿ��Թ���ͼ��������ƺ���Ĵ洢�ṹ�������Ա��a��b�ͣ����a��b��һ������a->b��Ȼ��չ����������

�������ʽ��

��һ��������������n��m����ʾԱ�������ʹ�����

����m�У�ÿ��2������a��b����ʾĳ��������Ϊa��Ա���Ľ���Ӧ����b��Ա���ߡ�

�������ʽ��

���޷��ҵ��������������롰POOR!��;����������ٵĽ�������

������������

2 1

1 2

�����������

201
'''
#include <stdio.h>

#define MAX_EMPLOYEES 1000

int inDegree[MAX_EMPLOYEES];   // �������
int bonus[MAX_EMPLOYEES];      // Ա����������
int graph[MAX_EMPLOYEES][MAX_EMPLOYEES];   // ͼ���ڽӾ���

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // ��ʼ����Ⱥͽ�������
    for (int i = 0; i < n; i++) {
        inDegree[i] = 0;
        bonus[i] = 100;   // ��ͽ���Ϊ100Ԫ
    }

    // ����ͼ���ڽӾ���
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a-1][b-1] = 1;   // a��Ա����b��Ա���ͣ�����һ����a->b
        inDegree[b-1]++;       // b��Ա������ȼ�1
    }

    // ��������
    int queue[MAX_EMPLOYEES];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int cur = queue[front++];
        
        for (int i = 0; i < n; i++) {
            if (graph[cur][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    queue[rear++] = i;
                }
                // �������������˳����½���
                if (bonus[cur] + 1 > bonus[i]) {
                    bonus[i] = bonus[cur] + 1;
                }
            }
        }
    }

    // ����Ƿ���ڻ�
    for (int i = 0; i < n; i++) {
        if (inDegree[i] > 0) {
            printf("POOR!\n");
            return 0;
        }
    }

    // �������ٽ�������
    int totalBonus = 0;
    for (int i = 0; i < n; i++) {
        totalBonus += bonus[i];
    }

    printf("%d\n", totalBonus-1);
    return 0;
}


