'''
【问题描述】

在循环队列中，以front和length分别表示循环队列中的队头位置和队列中所含元素的个数。试完成循环队列判断队空、判断队满入队和出队函数、获取队头元素及输出的操作，在主函数中调用以上函数，完成杨辉三角的输出。

【希冀测试数据说明】

1）从键盘输入数字n

2）输出对应的杨辉三角；若队列满了，输出杨辉三角的前面若干行；然后输出队列已满；

【输入形式】

3

【输出形式】

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
}Pascal;//定义杨辉三角队列类
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
bool EnPascal(Pascal *&q,ElemType e){//对第e行操作
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

