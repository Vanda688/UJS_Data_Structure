'''
����������������������е�ÿ�����ֵΪ�����ַ������ö�������Ľṹ�洢�����һ���㷨��������������������������ֵΪx�Ľ��������㣬����ֵΪx�Ľ����Ψһ�ġ�
��������ʽ��

AB#C##DE#F###

D

�������ʽ��

EF

������˵����

���������x�����NONE
�����ֱ�׼��
'''
#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode{
    char data;
    struct BTNode* lchild;
    struct BTNode* rchild;    
}BTNode;

BTNode* CreateTree(){
    char c;
    scanf("%c",&c);
    if(c=='#'){
        return NULL;
    }
    BTNode* new=(BTNode*)malloc(sizeof(BTNode));
    new->data=c;
    new->lchild=CreateTree();
    new->rchild=CreateTree();
    return new;
}

void Printx(BTNode* a){
    if(a!=NULL){
        printf("%c",a->data);
        Printx(a->lchild);        
        Printx(a->rchild);
    }
}

void Findx(BTNode* a,char x,BTNode** result,int* flag){
    if(a!=NULL && !*flag){
        if(a->data==x){
            *result=a;
            *flag=1;
        }
        Findx(a->lchild,x,result,flag);        
        Findx(a->rchild,x,result,flag);
    }
}

int main(){
    BTNode* root=CreateTree();
    char x;
    scanf("\n%c",&x);
    BTNode* result=NULL;
    int flag=0;
    Findx(root,x,&result,&flag);
    if(result==NULL){
        printf("NONE");
    }
    else{
        if(result->lchild==NULL && result->rchild==NULL){ // �ж��Ƿ�ΪҶ�ӽڵ�
            printf("NULL");
        }
        else{
            Printx(result->lchild);
            Printx(result->rchild);
        }
    }
    return 0;
}


