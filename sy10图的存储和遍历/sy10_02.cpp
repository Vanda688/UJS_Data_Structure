'''
【问题描述】

从键盘输入无向图的顶点信息，以！作为结束；

输入一组顶点信息,以-1 -1 作为结束

输出连通分量的个数。

【样例输入】

ABCDEF!

0 1

0 3

1 2

2 3

4 5

-1 -1

【样例输出】

2
'''
#include<stdio.h>
#include<stdlib.h>
#define Max 20
typedef struct Mg{
	char vertex[Max];
	int vertexNum;
	int arc[Max][Max];
	int vt[Max];
};
void Create(Mg*&G){
	G=(Mg*)malloc(sizeof(Mg));
	char c;
	int num=0,m,n;
	while(1){
		scanf("%c",&c);
		if(c=='!'){
			break;
		}
		else{
			G->vertex[num]=c;
			num++;
		}
	}
	G->vertexNum=num;
	for(m=0;m<num;m++){
		G->vt[m]=0;
		for(n=0;n<num;n++){
			G->arc[m][n]=0;
		}
	}
	while(1){
		scanf("%d %d",&m,&n);
		if(m==-1&&n==-1){
			break;
		}
		else{
			G->arc[m][n]=1;
		}
	}
}
int DFS(Mg*G,int p){
	G->vt[p]=1; 
	int i;
	for(i=0;i<G->vertexNum;i++){
		if(G->arc[p][i]==1&&G->vt[i]==0){
			DFS(G,i);
		}
	}
}
int main(){
	int num=1,i=0;
	Mg*G;
	Create(G);
	DFS(G,0);
	for(i=1;i<G->vertexNum;i++){
		if(G->vt[i]==0){
			DFS(G,i);
			num++;
		}		
	}
	printf("%d",num);
	return 0;
}


