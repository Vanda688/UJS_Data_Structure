'''
【问题描述】编写一个算法，将一个n阶矩阵A的元素从左上角开始，按照蛇形方式按行优先存储到一维数组中B中，并且以矩阵的格式输出矩阵A和B
【输入形式】输入n及若干个值
【输出形式】输出A和B中的数据元素的值
【样例输入】

4

1 4 2 8 5 7 1 4 2  8 5 7  1 4 2 8

【样例输出】

1 4 2 8

5 7 1 4

2 8 5 7

1 4 2 8



1 5 2 1

4 8 7 4

2 1 5 2

8 7 4 8
'''
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,i,j;
    scanf("%d", &n);
    int a1[n*n];
    for(i=0;i<n*n;i++){
    	scanf("%d",&a1[i]);
	}
	int a2[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a2[i][j]=a1[n*i+j];
			printf("%d ",a2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",a2[j][i]);
		}
		printf("\n");
		i++;
		if(i==n){
			break;
		}
		for(j=n-1;j>=0;j--){
			printf("%d ",a2[j][i]);
		}
		printf("\n");
	}
    return 0;
}


