'''
【问题描述】设计一个不带头结点的单链表L,请反向输出L中所有的结点存储的数据元素的值。
【输入形式】从键盘输入整数n，表示节点的个数；然后依次输入n个整数
【输出形式】逆序输出所有结点的个数。
【样例输入】

5

1 2 3 4 5
【样例输出】

5 4 3 2 1 
【样例说明】

若输入n的值小于0，请允许重新输入，直到n大于0为止。
【评分标准】
'''
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node {
	ElemType data;
	struct Node* next;
}Node;
void create(Node*& L,int n) {
	L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
}
int add(Node*& L,int p) {
	Node* s;
	s = (Node*)malloc(sizeof(Node)); 
	s->data = p;
	s->next = L;
	L = s;
	return 1;
}
void print(Node* L,int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", L->data);
		L = L->next;
	}
}
int main(){
	int n,i;
	Node* L;
	scanf("%d", &n);
	while(n<0){
		scanf("%d", &n);
	}
	create(L, n);
	for (i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		add(L,temp);
	}
	print(L, n);
	return 0;
}

