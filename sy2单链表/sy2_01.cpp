'''
������������

��Դ�ͷ���ĵ������Ա�д���к�����

��a����λ�������ڵ�������Ѱ�Ҹ���ֵ�Ľ�㡣���ҵ����򷵻ظý��ĵ�ַ�����ص��ڸ���ֵ�ĵ�һ������λ�򼴿ɣ�����ʵ�ʵ�ַ�������򷵻ؿա�

��b��ͳ�ƺ�����ͳ�Ƶ������е��ڸ���ֵe��Ԫ�ظ�����

�����������а������²�����в���

�������������->������ֵ->�������->��λĳ��Ԫ��->������ֵe->ͳ��������ֵΪe�Ľ�����


��������ʽ��

  6   // ��ʼ������

  4 2 1 6 2 5  //����6����ֵ

  7   //��λԪ��7

  2 // ͳ��Ԫ��ֵΪ2�Ľ�����


�������ʽ��

  4 2 1 6 2 5

  error

  2
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
int Locate(LNode *L,int a){
	int num=0;
    while (L!=NULL) {
	    if (L->data == a) {
	        return num; // �ҵ�Ŀ���㣬�������ַ
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



