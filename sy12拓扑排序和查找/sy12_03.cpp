'''
【题目】

由于公司员工在总决选中胜出，CS COMPANY总经理Ms.Z 心情好，决定给每位员工发奖金。公司决定以每个人本年度在公司的贡献为标准来计算他们得到的奖金多少。

于是，Ms.Z召开m方会谈。每位参加会谈的代表提出自己的意见：“我认为员工a的奖金应该比b高！”Mr.Z 决定要找出一种奖金方案，满足各位代表的意见，并且同时使得总奖金数最少。每位员工奖金为整数，最低100元。

【提示】本题可以是拓扑排序的应用，首先可以构建图（自行设计合理的存储结构），如果员工a比b低，则从a到b有一条弧，a->b，然后展开拓扑排序。

【输入格式】

第一行输入两个整数n，m，表示员工总数和代表数

以下m行，每行2个整数a、b，表示某个代表认为a号员工的奖金应当比b号员工高。

【输出格式】

若无法找到合理方案，则输入“POOR!”;否则输出最少的奖金总数

【测试样例】

2 1

1 2

【输出样例】

201
'''
#include <stdio.h>

#define MAX_EMPLOYEES 1000

int inDegree[MAX_EMPLOYEES];   // 入度数组
int bonus[MAX_EMPLOYEES];      // 员工奖金数组
int graph[MAX_EMPLOYEES][MAX_EMPLOYEES];   // 图的邻接矩阵

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 初始化入度和奖金数组
    for (int i = 0; i < n; i++) {
        inDegree[i] = 0;
        bonus[i] = 100;   // 最低奖金为100元
    }

    // 构建图的邻接矩阵
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a-1][b-1] = 1;   // a号员工比b号员工低，存在一条边a->b
        inDegree[b-1]++;       // b号员工的入度加1
    }

    // 拓扑排序
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
                // 根据拓扑排序的顺序更新奖金
                if (bonus[cur] + 1 > bonus[i]) {
                    bonus[i] = bonus[cur] + 1;
                }
            }
        }
    }

    // 检查是否存在环
    for (int i = 0; i < n; i++) {
        if (inDegree[i] > 0) {
            printf("POOR!\n");
            return 0;
        }
    }

    // 计算最少奖金总数
    int totalBonus = 0;
    for (int i = 0; i < n; i++) {
        totalBonus += bonus[i];
    }

    printf("%d\n", totalBonus-1);
    return 0;
}


