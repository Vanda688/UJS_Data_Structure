'''
【问题描述】采用邻接矩阵作为存储结构，利用深度优先搜索，判断有向图中，是否存在从顶点i到顶点j的路径；

 要求：

从键盘输入若干个字符(表示顶点自带的信息),直到！结束->再输入若干对顶点编号（从0开始，表示两个顶点之间存在一条边），直到输入-1 -1结束-->输出对应的邻接矩阵 -->输入查询的顶点-->输出T 或者F
【输入形式】

ABCDE!

0 1

0 2

1 3

1 2

2 3

3 4

-1 -1

BE

【输出形式】

0 1 1 0 0

0 0 1 1 0

0 0 0 1 0

0 0 0 0 1

0 0 0 0 0

T
'''
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *lchild;
    struct node *rchild;
}Node, *Bitree;

char ch;
Bitree T;

Node *CreateBitree() {
    scanf("%c", &ch);
    Bitree T;
    if (ch == '#') {
        T = NULL;
    } else {
        T = (Node *)malloc(sizeof(Node));
        T->data = ch;
        T->lchild = CreateBitree();
        T->rchild = CreateBitree();
    }
    return T;
}
void Level(Bitree T) {
    int front = 0, rear = 0;
    Bitree q[50];
    if(T) {
        q[rear++] = T;
    }
    while (front != rear) {
        Bitree p = q[front++];
        printf("%c", p->data);
        if (p->lchild) {
            q[rear++] = p->lchild;
        }
        if (p->rchild) {
            q[rear++] = p->rchild;
        }
    }
}
int bfs(Bitree T) {
    int flag = 1;
    int bj = 1;
    Bitree u;
    u = T;
    int q[10000], front = 0, end = 0;
    q[end++] = u;
    while (front != end) {
        u = q[front++];
        if (u->lchild && u->rchild) {
            if (bj == 0) flag = 0;
            if (!flag) break;
            q[end++] = u->lchild;
            q[end++] = u->rchild;
        }
        if (!u->lchild && u->rchild) {
            flag = 0;
            break;
        }
        if (u->lchild && !u->rchild) {
            if (!bj) flag = 0;
            bj = 0;
            if (!flag) break;
            q[end++] = u->lchild;
        }
        if (!u->lchild && !u->rchild) {
            bj = 0;
            if (!flag) break;
        }
    }
    if (flag) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Bitree T;
    T = CreateBitree();
    Level(T);
    if (bfs(T)) {
        printf("\nYES");
    } else {
        printf("\nNO");
    }
    return 0;
}


