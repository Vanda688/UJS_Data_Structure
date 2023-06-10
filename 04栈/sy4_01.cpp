'''
【问题描述】

请设计两个顺序栈共享一个存储空间形成的共享栈，完成共享栈的入栈、出栈和判断栈空、输出等四个函数，并在主函数调用以上基本函数进行测试。

为了便于测试，请大家设置共享栈的容量为12；

希冀平台测试数据及说明：

1）输出栈1； 空栈输出stack1:  empty

2）输出栈2； 空栈输出stack2:  empty

3）输入整数n；

4）将n以内（不含n）的奇数入栈1；若栈满，输出full，停止入栈

5）将n以内的偶数（不含n）入栈2；若栈满，输出full，停止入栈

6）栈1出栈, 输出该元素；

7）栈2出栈，输出该元素；

8）输出栈1；（从栈顶到栈底）

9）输出栈2；（从栈顶到栈底）

【样例输入】

6
【样例输出】
stack1:  empty

stack2:  empty

5

4

stack1:3 1

stack2:2
'''
#include<stdio.h>
#include<stdlib.h>
#define N 12
#define ElemType int
typedef struct{
	ElemType data[N];//
	int top1,top2;
}DStack;
void Create(DStack *&s1,DStack *&s2){
	s1=(DStack *)malloc(sizeof(DStack));
	s2=(DStack *)malloc(sizeof(DStack));
	s1->top1=-1;
	s2->top2=N;
} 
bool Push(DStack *&s1,DStack *&s2,int i,ElemType e){
	if(s1->top1>=s2->top2-1){
		return false;
	}
	if(i==0){
		s1->top1++;
		s1->data[s1->top1]=e;
	}
	else{
		s2->top2--;
		s2->data[s2->top2]=e;
	}
	return true;
}
bool Pop(DStack *&s1,DStack *&s2,int i,ElemType &e){
	if(i==0){
		if(s1->top1==-1){
			return false;
		}
		e=s1->data[s1->top1];
		s1->top1--;
		return true;
	}
	else{
		if(s2->top2==N){
			return false;
		}
		e=s2->data[s2->top2];
		s2->top2++;
		return true;
	}
}
bool Empty(DStack *&s1,DStack *&s2,int i){
	if(i==0){
		return(s1->top1==-1);
	}
	else{
		return(s2->top2==N);
	}
}
bool Full(DStack *&s1,DStack *&s2){
	return(s1->top1==s2->top2-1);
}
bool PopAll(DStack *&s1,DStack *&s2,int i){
	if(i==0){
		printf("stack1:");
		if(s1->top1==-1)
			return false;
		while(s1->top1!=-1){
			printf("%d ",s1->data[s1->top1]);
			s1->top1--;	
		}
		return true;
	}
	else{
		printf("stack2:");
		if(s2->top2==N)
			return false;
		while(s2->top2!=N){
			printf("%d ",s2->data[s2->top2]);
			s2->top2++;	
		}
		return true;
	}
}
int main(){
	int n,i,e;
	DStack *s1,*s2;
	Create(s1,s2);
	scanf("%d",&n);
	if(Empty(s1,s2,0)==true){
		printf("stack1:empty\n");
	}
	if(Empty(s1,s2,1)==true){
		printf("stack2:empty\n");
	}
	for(i=1;i<n;i+=2){
		if(Full(s1,s2)==true){
			printf("full\n");
			break;
		}
		Push(s1,s2,0,i);
	}
	for(i=2;i<n;i+=2){
		if(Full(s1,s2)==true){
			printf("full\n");
			break;
		}
		Push(s1,s2,1,i);
	}
	if(Pop(s1,s2,0,e))
		printf("%d\n",e);
	else
		printf("error\n");
	if(Pop(s1,s2,1,e))
		printf("%d\n",e);
	if(!PopAll(s1,s2,0))
		printf("empty");
	printf("\n");
	if(!PopAll(s1,s2,1))
		printf("empty");
	return 0;
}

