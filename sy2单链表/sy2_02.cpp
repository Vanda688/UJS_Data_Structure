'''
【问题描述】

针对带头结点的单链表，

（a）   设计算法返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。

（b）   查找链表的倒数第k个结点。

在主函数中依次实现以下操作完成测试,注意，为了测试的正确性，请不要随意加入任何提示性输出。

1.  从键盘输入单链表中个数；

2.  输入单链表中数值；

3.  输出单链表；

4.  输出单链表的中间结点

5.  输入k值

6.  输出单链表的倒数第k个元素。


【样例输入】

 5

 4 5 2 3 7

 6


【样例输出】

 4 5 2 3 7

2

 error


【样例说明】
若给定值k超过表长，输出error。
'''
#include<stdio.h>
#include<stdlib.h>
//定义单链表结构体 
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*L;
void Create(LNode *&L,int a[],int n){
	LNode *s;
	L=(LNode *)malloc(sizeof(LNode));
	L->next=NULL;
	for(int i=0;i<n;i++){
		s=(LNode *)malloc(sizeof(LNode));
		s->data=a[i];
		s->next=L->next;
		L->next=s;
	}
}
int Mid(LNode *L,int a){
	int i,j;
	LNode *q = L->next;
	if(a%2==0){
		j=(a/2);
	} 
	else{
		j=(a-1)/2;
	}
    for(i=0;i<j;i++){
	    q=q->next;
	}
	return q->data;
}
int K(LNode *L,int k,int m){
	int i;
	LNode *s = L->next;
	if(m-k<0){
		return -1;
	}
	else{
		for(i=0;i<m-k;i++){
	        s=s->next;
    	}
    return s->data;
	}
}
int main(){
	int i,m,k;
	scanf("%d",&m);
	int a[m],b[m]; 
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);	
	for(i=0;i<m;i++){
		b[i]=a[m-1-i];
	}
	LNode *L;	
	Create(L,b,m);
	LNode *p = L->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n%d",Mid(L,m));
	if(K(L,k,m)!=-1){
		printf("\n%d",K(L,k,m));
	}
	else{
		printf("\nerror");
	}
	return 0;
}




