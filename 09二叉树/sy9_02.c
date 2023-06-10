'''
【问题描述】从键盘输入一个字符序列，构建二叉树b,输出其层次遍历序列，判断b是否为完全二叉树,是则输出YES,不是则输出NO

【输入形式】

AB#C##DE#F###

【输出形式】

ABDCEF

NO
【提示】

根据完全二叉树的定义，对完全二叉树进行层次遍历应该满足以下条件：

若某结点没有左孩子，则一定没有右孩子；

若某结点缺左孩子或右孩子，则它所有的后继结点一定都没有孩子。

若不满足上述任何一个条件，都不是完全二叉树。
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


