'''
�������������õ�����洢һԪ����ʽ�����ݽڵ㰴��ָ����С�������򣩣���д�㷨ʵ������һԪ����ʽ��ӡ�
��������ʽ���ֱ�������������ʽ�����ϵ����ָ������-100��Ϊ�������

�������ʽ���������ʽ�ĺ�
���������롿

 1 3 2 4 3 5 -100

 2 3 4 5 -100
�����������

 3 3 2 4 7 5 
������˵����
�����ֱ�׼��
'''
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data[2];
	struct Node *next;//����ṹ��ָ�룬ָ������ڵ㣬�γ����� 
}Node;
typedef struct List
{
	Node *next;//����ṹ��ָ�룬ָ������ڵ㣬�γ����� 
}List;
void Create(List *&h,int &Flag)//���������б�ĺ��� 
{
	Node *r,*s;
	h=(List*)malloc(sizeof(List));//����ͷ�ڵ� 
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
	h=(List*)malloc(sizeof(List));//����ͷ�ڵ� 
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

