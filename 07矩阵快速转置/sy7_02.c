'''
【问题描述】
 求n个数中第k大的数

【输入形式】
 第一行n k，第二行为n个数，都以空格分开

【输出形式】
 第k大的数

【样例输入】

10 3
18 21 11 26 12 2 9 33 43 28

【样例输出】

28

【样例说明】

【评分标准】
 时间复杂度大于等于O(k*n)的方法得一半分，时间复杂度小于等于O(n*log2k)得满分。

提示：

1. 分析各种排序或查找算法的优缺点，分析解决具体问题的时间复杂度，进而找出更高效的算法。

2. n与k的值不同，不同算法的效率也会有影响，如n=10, k=9时，可以找第2小的数。
'''
#include<stdio.h>
#define Max 50
int main(){
	int n,k,i,j,max,a[Max];
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(j=1;j<n;j++){
		max=j-1;
		for(i=j;i<n;i++){
			if(a[max]<a[i]){
				int temp;
				temp=a[max];
				a[max]=a[i];
				a[i]=temp;
			}
		}
	}
	printf("%d",a[k-1]);
	return 0;
}




