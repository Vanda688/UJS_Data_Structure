'''
【问题描述】利用第二章线性表类型的基本定义，编写算法按行优先压缩存储n阶（即n行n列）下三角矩阵，并按照矩阵的样式输出。
【输入形式】从键盘输入n的值，然后依次输入若干个整数（整数个数为定值，请自行考虑整数个数和n的关系），其中最后一个数为上三角部分的常数C的值。
【输出形式】以矩阵的形式按照行列方式输出
【样例输入】

5

1 2 3 3 4 5 4 5 6 8 5 6 7 9 11 20
【样例输出】

1 20 20 20 20

2 3  20 20  20

3 4  5   20 20

4 5  6   8   20

5 6  7   9   11
'''
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n,num,i,j,k=0;
	scanf("%d",&n);
	num=((1+n)*n)/2+1;
	int a1[num];
	for(i=0;i<num;i++){
		scanf("%d",&a1[i]);
	} 
	int a2[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j<=i){
				a2[i][j]=a1[k];
				k++;
			}
			else{
				a2[i][j]=a1[num-1];
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",a2[i][j]);
		}
		printf("\n");
	}
	return 0;	
}

