'''
������������

��Դ�ͷ���ĵ�����

��a��   ����㷨����������м��㡣����������м��㣬�򷵻صڶ����м��㡣

��b��   ��������ĵ�����k����㡣

��������������ʵ�����²�����ɲ���,ע�⣬Ϊ�˲��Ե���ȷ�ԣ��벻Ҫ��������κ���ʾ�������

1.  �Ӽ������뵥�����и�����

2.  ���뵥��������ֵ��

3.  ���������

4.  �����������м���

5.  ����kֵ

6.  ���������ĵ�����k��Ԫ�ء�


���������롿

 5

 4 5 2 3 7

 6


�����������

 4 5 2 3 7

2

 error


������˵����
������ֵk�����������error��
'''
#include<stdio.h>
#include<stdlib.h>
//���嵥����ṹ�� 
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




