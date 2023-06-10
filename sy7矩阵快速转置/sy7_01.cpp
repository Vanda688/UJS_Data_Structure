'''
【问题描述】从键盘输入矩阵的行、列和非零元素个数，以及若干组数据（分别表示系数矩阵非零元素的行、列和值），即三元组表对应的信息；为了便于观察结果，请将新三元组表中的每条记录均初值化为0，再开始完成矩阵的快速转置，并根据以下提示按顺序输出相应的内容
【输入形式】 

  行数m 列数n 非零元素个数t

  t组数据

【输出形式】

   按照行列形式输出该三元组表表示的矩阵；

   依次输出转置后每行第一个非零元素在新的三元组表中的下标；

   根据快速转置算法进行转置，插入第3条记录后，输出新的三元组表；

   按照行列形式输出转置之后的矩阵；

【样例输入】

   6 7 8

   0 1 12

   0 2 9

   2 0 3

   2 5 1

   3 2 24

   4 1 18

   5 0 5 

   5 3 7
【样例输出】 

   0 12 9 0 0 0 0

   0 0  0 0 0 0 0

   3 0  0 0 0 1 0  

   0 0 24 0 0 0 0

   0 18 0 0 0 0 0 

   5 0  0 7 0 0 0



   0 2 4 6 7 7 8



   0 2 3

   0 0 0

   1 0 12

   0 0 0

   2 0 9

   0 0 0

   0 0 0

   0 0 0



   0  0 3 0  0 5 

   12 0 0 0 18 0 

   9  0 0 24 0 0 

   0  0 0 0  0 7

   0  0 0 0  0 0

   0  0 1 0  0 0

   0  0 0 0  0 0





【样例说明】
【评分标准】
'''
#include<stdio.h>
#define Max 50
typedef struct{
	int r,c,d;//行 列 值 
}TupNode;//三元组类型 
typedef struct{
	int r,c,n;//行 列 元素个数 
	TupNode data[Max];
}TSMatrix;//三元组类型 
void printMat(TSMatrix t){
	int m,n,k=0;//m行n列 ,k为三元组序号,从0开始遍历 
	for(m=0;m<t.r;m++){
		for(n=0;n<t.c;n++){
			if(m==t.data[k].r&&n==t.data[k].c){
				printf("%d ",t.data[k].d);
				k++;
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}
void printTup(TSMatrix t){
	int i;
	for(i=0;i<t.n;i++){
		printf("%2d%2d%2d\n",t.data[i].r,t.data[i].c,t.data[i].d);
	}
}
void trans_init(TSMatrix t,TSMatrix &t2){
	int i;
	t2.r=t.c;
	t2.c=t.r;
	t2.n=t.n;
	for(i=0;i<t2.n;i++){
		t2.data[i].r=0;
		t2.data[i].c=0;
		t2.data[i].d=0;
	}
}
void trans(TSMatrix t,TSMatrix &t2){
	int temp[t2.r];
	int i,j,k=0;
	for(i=0;i<t2.r;i++){
		temp[i]=0;
		for(j=0;j<t.n;j++){
			if(i==t.data[j].c){
				temp[i]++;
			}
		}		
	}
	for(i=0;i<t2.r;i++){
		printf("%2d",k);
		k+=temp[i];
	}
	printf("\n");
	printf("\n");
	for(i=0;i<t2.n;i++){
		int i2=0;//i2为元素在新三元组的下标 
		for(j=0;j<t2.n;j++){
			if(t.data[i].c==t.data[j].c&&t.data[i].r>t.data[j].r){
				i2++;
			}
		}
		for(j=0;j<t.data[i].c;j++){
			i2+=temp[j];
		}
		t2.data[i2].r=t.data[i].c;
		t2.data[i2].c=t.data[i].r;
		t2.data[i2].d=t.data[i].d;
		if(i==2){
			printTup(t2);
			printf("\n");
		}
	}
}
int main(){
	TSMatrix t,t2;
	int i;
	scanf("%d %d %d",&t.r,&t.c,&t.n);
	for(i=0;i<t.n;i++){
		scanf("%d %d %d",&t.data[i].r,&t.data[i].c,&t.data[i].d);
	}
	printMat(t);
	printf("\n");
	trans_init(t,t2);
	trans(t,t2);
	printMat(t2);
	return 0;
} 

