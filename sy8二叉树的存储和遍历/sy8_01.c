'''
【问题描述】

 1.从键盘输入扩展二叉树的先序遍历序列，构建另一棵二叉树;

 2.交换二叉树中所有度为2的结点的左右子树，输出交换后的二叉树中序遍历序列；

 3.统计二叉树中左右子树高度相等的结点数。（注意：叶子节点也算高度相等） 

【输入形式】

  ABD#E###CF##G##

【输出形式】

  GCFADEB

  4
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
void MidPrint(BTNode* b){
	if(b!=NULL){
		MidPrint(b->lchild);
		printf("%c",b->data);
		MidPrint(b->rchild);
	}
}
void Swap(BTNode* b){
	if(b==NULL){
		return;
	}
	Swap(b->lchild);
	Swap(b->rchild);
	if(b->lchild!=NULL&&b->rchild!=NULL){
		BTNode* temp = b->lchild;
		b->lchild=b->rchild;
		b->rchild=temp;
	}
}
int High(BTNode* b){
	int h,left,right;
	if(!b){
		return h=0;
	}
	else{
		left=High(b->lchild);
		right=High(b->rchild);
		h=(left>right?left:right)+1;
	}
	return h;
}
int EqualNum(BTNode* b){
	int Num=0;
	if(b==NULL){
		return 0;
	}
	int left=High(b->lchild);
	int right=High(b->rchild);
	if(left==right){
		Num+=1;
	}
	else{
		Num+=0;
	}
	Num+=EqualNum(b->lchild)+EqualNum(b->rchild);
	return Num;
}
int main(){
	BTNode* root=CreateTree();
	Swap(root);
	if(!root){
		printf("NULL");
	}
	MidPrint(root);
	printf("\n%d",EqualNum(root));
	return 0;
}

