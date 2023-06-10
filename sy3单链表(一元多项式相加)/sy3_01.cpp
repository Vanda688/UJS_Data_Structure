'''
【问题描述】用单链表存储一元多项式（数据节点按照指数从小到大排序），编写算法实现两个一元多项式相加。
【输入形式】分别输入两个多项式各项的系数和指数，以-100作为输入结束

【输出形式】输出多项式的和
【样例输入】

 1 3 2 4 3 5 -100

 2 3 4 5 -100
【样例输出】

 3 3 2 4 7 5 
【样例说明】
【评分标准】
'''
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data[2];
	struct Node *next;//定义结构体指针，指向后续节点，形成链表 
}Node;
typedef struct List
{
	Node *next;//定义结构体指针，指向后续节点，形成链表 
}List;
void Create(List *&h,int &Flag)//创建方程列表的函数 
{
	Node *r,*s;
	h=(List*)malloc(sizeof(List));//创建头节点 
	h->next=NULL;
	while(1){
		s=(Node*)malloc(sizeof(Node));
		scanf("%d",&s->data[0]);
		if(s->data[0]==-100)
		{
			break;
		}
		if(s->data[0] == 0)
		{
			scanf("%d",&s->data[1]);
			continue;
		}
		scanf("%d",&s->data[1]);
		if(h->next==NULL)
		{
			h->next=s;
		}
			
		else
		{
			r->next=s;
		}
		r=s;
	}
	if(h->next!=NULL)
	{
		r->next=NULL;
		Flag=0;
	}
	else
	{
		Flag=-1;
	} 
}
void DispTable(List *h)
{
	Node *p=h->next;
	while(p!=NULL)
	{
		printf("%d %d ",p->data[0],p->data[1]);
		p=p->next;
	}
}
void LinkTable(List *h1,List *h2,List *&h)
{
	Node *p=h1->next,*q=h2->next,*r,*s;
	h=(List*)malloc(sizeof(List));//创建头节点 
	h->next=NULL;
	while(p!=NULL&&q!=NULL) 
	{
        s = (Node*)malloc(sizeof(Node));
        if (p->data[1] < q->data[1]) 
		{
            s->data[0] = p->data[0];
            s->data[1] = p->data[1];
            p = p->next;
            if(s->data[0]==0) continue; 
        } 
		else if (p->data[1] > q->data[1]) 
		{
            s->data[0] = q->data[0];
            s->data[1] = q->data[1];
            q = q->next;
            if(s->data[0]==0) continue; 
        } 
		else 
		{
            s->data[0] = p->data[0] + q->data[0];
            s->data[1] = p->data[1];
            p = p->next;
            q = q->next;
            if(s->data[0]==0) continue; 
        }
		if(h->next==NULL)
		{
			h->next=s;
			r=s;
		}
		else
		{
			s->next=NULL;
			r->next=s;
			r=r->next;
		}
	}
	while(p!=NULL)
	{
		s=(Node*)malloc(sizeof(Node));
		s->data[0] = p->data[0];
        s->data[1] = p->data[1];
        p=p->next;
        s->next=NULL;
		r->next=s;
		r=r->next;
		r=s;
	}
	while(q!=NULL)
	{
		s=(Node*)malloc(sizeof(Node));
		s->data[0]=q->data[0];
        s->data[1]=q->data[1];
        q=q->next;
        s->next=NULL;
		r->next=s;
		r=r->next;
		r=s;
	}
}
void Destroy(List *&h)
{
	Node *pre=h->next,*p=pre->next;
	while(p!=NULL)
	{
		free(pre);
		pre=p;p=p->next;
	}
	free(pre);
	free(h);
}
int main()
{
	List *h1,*h2,*h;
	int Flag1,Flag2;
	Create(h1,Flag1);
	Create(h2,Flag2);
	if(Flag1==-1&&Flag2==-1)
	{
		printf("0");
	}
	else if(Flag1==-1)
	{
		DispTable(h2);
	}
	else if(Flag2==-1)
	{
		DispTable(h1);
	}
	else
	{
		LinkTable(h1,h2,h);
		DispTable(h);
	}
	Destroy(h1);
	Destroy(h2);
	Destroy(h);
	return 0;
}

