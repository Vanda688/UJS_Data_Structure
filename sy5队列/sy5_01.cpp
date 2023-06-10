'''
������������

��ѭ�������У���front��length�ֱ��ʾѭ�������еĶ�ͷλ�úͶ���������Ԫ�صĸ����������ѭ�������ж϶ӿա��ж϶�����Ӻͳ��Ӻ�������ȡ��ͷԪ�ؼ�����Ĳ��������������е������Ϻ��������������ǵ������

��ϣ����������˵����

1���Ӽ�����������n

2�������Ӧ��������ǣ����������ˣ����������ǵ�ǰ�������У�Ȼ���������������

��������ʽ��

3

�������ʽ��

1

1 1

1 2 1
'''
#include<stdio.h>
#include<stdlib.h>
#define Max 50
#define ElemType int
typedef struct{
    ElemType data[Max][Max];
    int front,length,max;
}Pascal;//����������Ƕ�����
void Init(Pascal *&q) {
    q=(Pascal *)malloc(sizeof(Pascal));
    q->front=0;
    q->length=0;
}
void Create(Pascal *&q){
    Init(q);
    int n,i;
    bool EnPascal(Pascal *&q,ElemType e);
    scanf("%d",&n);
    q->front=0;
    q->max=n;
    for(i=1;i<n+1;i++){
    	EnPascal(q,i);
	}
}
bool Empty(Pascal *&q){
    return(q->length==0);
}
bool Full(Pascal *q){
    return(q->length==q->max);
}
bool EnPascal(Pascal *&q,ElemType e){//�Ե�e�в���
    int i;
    if(Full(q)){
    	printf("full");
        return false;
    }
    q->data[e-1][0]=q->data[e-1][e-1]=1;
    for(i=1;i<e-1;i++){
        q->data[e-1][i]=q->data[e-2][i-1]+q->data[e-2][i];
    }
    q->length++;
    return true;
}
bool DePascal(Pascal *&q,ElemType e,int a[]){
    int i;
    if(Empty(q)){
        return false;
    }
    for(i=0;i<e;i++){
    	//printf("%d",q->data[e-1][i]);
        a[i]=q->data[e-1][i];
    }
    //*a=&q->data[e-1][0];
    return true;
}
bool GetHead(Pascal *q,ElemType *x){
    if (Empty(q)){
        return 0;
    }
    x=q->data[q->front];
    return 1;
}
bool PrintPascal(Pascal *q) {
	if (Empty(q)){
        return 0;
    }
    int a[Max];
    int i,j;
    for(i=1;i<q->max+1;i++){
        DePascal(q,i,a);
        for(j=0;j<i;j++){
            printf("%d ",a[j]);
        }
        printf("\n");
    }
    return 1;
}
int main(){
    Pascal *q;
    Create(q);
    //PrintPascal(q);
    if(!PrintPascal(q)){
    	printf("error");
	}
    return 0;
}

