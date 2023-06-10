'''
【问题描述】

针对带头结点的单链表，试编写下列函数：

（a）定位函数：在单链表中寻找给定值的结点。若找到，则返回该结点的地址（返回等于给定值的第一个结点的位序即可，并非实际地址），否则返回空。

（b）统计函数：统计单链表中等于给定值e的元素个数。

在主函数当中按照以下步骤进行测试

输入链表结点个数->输入数值->输出链表->定位某个元素->输入数值e->统计链表中值为e的结点个数


【输入形式】

  6   // 初始结点个数

  4 2 1 6 2 5  //输入6个数值

  7   //定位元素7

  2 // 统计元素值为2的结点个数


【输出形式】

  4 2 1 6 2 5

  error

  2
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
int Locate(LNode *L,int a){
	int num=0;
    while (L!=NULL) {
	    if (L->data == a) {
	        return num; // 找到目标结点，返回其地址
	    }
	    num++;
	    L=L->next;
	}
	return -1;
}
int Sta(LNode *L,int a){
	int num=0;
	while(L!=NULL){
		if (L->data == a) {
            num++;
        }
        L=L->next;
	}
	return num;
}
int main(){
	int i,m,x,y;
	scanf("%d",&m);
	int a[m],b[m]; 
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&x);
	scanf("%d",&y);
	
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
	if(Locate(L,x)!=-1){
		printf("\n%d",Locate(L,x));
	}
	else{
		printf("\nerror");
	}
	printf("\n%d",Sta(L,y));
	return 0;
}



