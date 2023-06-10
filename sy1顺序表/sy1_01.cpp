'''
【问题描述】

设计一个有序顺序表，即表中的数据元素按数据元素值递增有序。实现以下函数：

（a）合并两个有序表，得到一个新的有序表。

（b）寻找两个有序表的中位数。

 例如： arr1=[1,3] arr2=[2]

 则这两个有序表的中位数是2.

 对于一个有序表L，当有序表表长L为奇数时，中位数的位序为L/2+1，L为偶数时，中位数位序为L/2。

 举例：顺序表[1，3，4，5，6，7，8]，L=7，中位数为5。

   
在主函数中依次实现以下操作完成测试,注意，为了测试的正确性，请不要随意加入任何提示性输出。

1.  从键盘依次输入若干整数，创建初始的两个有序顺序表，-1表示输入结束；

2.  输出两个有序顺序表中的元素；

3.  输出合并之后的有序顺序表；

4.输出寻找到的两个有序表的中位数位序及中位数。


【样例输入】

 2 7 8 -1

 4 5 9 10 -1

【样例输出】

  2 7 8

  4 5 9 10

  2 4 5 7 8 9 10

  4 7 

'''
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;
void InitList(SqList *L)
{
	L->length=0;
} 
void ListInsert(SqList *L,int x)
{
	L->data[L->length]=x;
	L->length++;
}
void UnionList(SqList A,SqList B,SqList *C)
{
	int i=0,j=0,k=0;//i.j�ֱ�ΪLA��LB���±꣬kΪLC��Ԫ�صĸ���
	while(i<A.length&&j<B.length)
	{
		if(A.data[i]<B.data[j])
		{
			C->data[k]=A.data[i];
			i++;k++;
		}
		else
		{
			C->data[k]=B.data[j];
			j++;k++;
		}
	}
	while(i<A.length)
	{
		C->data[k]=A.data[i];
		i++;k++;
	}
	while(j<B.length)
	{
		C->data[k]=B.data[j];
		j++;k++;
	}
	C->length=k;
}
/*void UnionList(SqList*LA,SqList*LB,SqList*&LC)
{
	int i=0,j=0,k=0;//i.j�ֱ�ΪLA��LB���±꣬kΪLC��Ԫ�صĸ���
	LC=(SqList*)malloc(sizeof(SqList)); //��������˳���LC
	while(i<LA->length&&j<LB->length)
	{
		if(LA->data[i]<LB->data[j])
		{
			LC->data[k]=LA->data[i];
			i++;k++;
		}
		else
		{
			LC->data[k]=LB->data[j];
			j++;k++;
		}
	}
	while(i<LA->length)
	{
		LC->data[k]=LA->data[i];
		i++;k++;
	}
	while(j<LB->length)
	{
		LC->data[k]=LB->data[j];
		j++;k++;
	}
	LC->length=k;
}*/
//2.������λ��
ElemType M_search(SqList C,int *p) 
{
	int i,j,k=C.length;
	if(k%2==0)
	{
		i=k/2;
		j=i-1;
		*p=k/2;
		return (C.data[i]+C.data[j])/2;
	}
	else
	{
		i=(k-1)/2;
		*p=(k+1)/2;
		return C.data[i];
	}
}
//3.������ 
int main()
{
	int n,i,p; 
	SqList A,B,C;
	InitList(&A);
	InitList(&B);
	scanf("%d",&n);
	while(n!=-1)
	{
		ListInsert(&A,n);
		scanf("%d",&n);
	}
	scanf("%d",&n);
	while(n!=-1)
	{
		ListInsert(&B,n);
		scanf("%d",&n);
	}
	UnionList(A,B,&C);
	for(i=0;i<A.length;i++)
	{
		printf("%d ",A.data[i]);
	}
	printf("\n");
	for(i=0;i<B.length;i++)
	{
		printf("%d ",B.data[i]);
	}
	printf("\n");
	for(i=0;i<C.length;i++)
	{
		printf("%d ",C.data[i]);
	}	
	printf("\n");
	printf("%d %d",p,M_search(C,&p));
	return 0; 
}
                                   




