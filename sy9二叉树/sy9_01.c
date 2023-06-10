'''
【问题描述】假设二叉树中的每个结点值为单个字符，采用二叉链表的结构存储。设计一个算法，采用先序遍历方法求二叉树中值为x的结点的子孙结点，假设值为x的结点是唯一的。
【输入形式】

AB#C##DE#F###

D

【输出形式】

EF

【样例说明】

如果不存在x，输出NONE
【评分标准】
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
        if(result->lchild==NULL && result->rchild==NULL){ // 判断是否为叶子节点
            printf("NULL");
        }
        else{
            Printx(result->lchild);
            Printx(result->rchild);
        }
    }
    return 0;
}


