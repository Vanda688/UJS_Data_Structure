'''
������������

 ��������ʽ����һ�ö������������Ӽ�����������ҵ�Ԫ�أ������Ԫ�رȽ�·����
��������ʽ��

 �Ӽ�������һϵ������Ԫ��ֵ����-1��Ϊ������

 ��������ҵ�Ԫ��ֵ��
�������ʽ��

 ��������ʽ���ÿ����һ������֮�͵Ķ���������

 �������·��
���������롿


4 10 0 1 8 6 3 5 3 7 -1

9

���������

 //������������ʽ���ÿ����һ������֮�͵Ķ���������

4

4(,10)

4(0,10)

4(0(,1),10)

4(0(,1),10(8,))

4(0(,1),10(8(6,),))

4(0(,1(,3)),10(8(6,),))

4(0(,1(,3)),10(8(6(5,),),))

4(0(,1(,3)),10(8(6(5,),),))

4(0(,1(,3)),10(8(6(5,7),),))

4 10 8   //��һ���ǲ���·��

������˵����
�����ֱ�׼��
'''
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insertNode(Node* root, int value) {
    if (root == NULL){
        return createNode(value);
    }
    if (value < root->data){
        root->left = insertNode(root->left, value);
    } else if (value > root->data){
        root->right = insertNode(root->right, value);
    }
    return root;
}
void printTree(Node* root) {
    if (root != NULL) {
        printf("%d", root->data);
        if (root->left != NULL || root->right != NULL) {
            printf("(");
            printTree(root->left);
            printf(",");
            printTree(root->right);
            printf(")");
        }
    }
}
Node* buildBST(char temp[MAX],int num) {
    Node* root = NULL;
    int i;
    //printf("����������Ԫ��ֵ����-1��Ϊ��������\n");
    for(i=0;i<num;i++) {
        root = insertNode(root, temp[i]);
        printf("\n");
        printTree(root);
        //printf("\n");
    }
    return root;
}
Node* searchNode(Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (root->data == value){
    	printf("%d ",value);
    	return root;
	}

    if (value < root->data) {
        printf("%d ", root->data);
        return searchNode(root->left, value);
    } else {
        printf("%d ", root->data);
        return searchNode(root->right, value);
    }
}
void printInorder(Node* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}
int main() {
	int target,value,i,num=0;
	char temp[MAX];
	for(i=0;i<MAX;i++) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        else{
        	temp[i]= value;
        	num++;
		} 
    }
	scanf("%d", &target);
    Node* root = buildBST(temp,num);
    //printf("\n������������\n");
    //printInorder(root);
    printf("\n");
    //printf("\n����������ҵ�Ԫ�أ�\n");
    
    //printf("\nԪ�رȽ�·����\n");
    searchNode(root, target);
    printf("\n");
    return 0;
}





