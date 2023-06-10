'''
1.从键盘输入无向图若干个顶点信息，以！作为结束；

2.输入一组顶点信息，分别表示图中边依附的两个顶点和权值，以-1 作为输入结束；以邻接矩阵作为存储；

3.输入起始顶点

4.利用prim算法求解最小生成树，输出每一步选出的边；

5.输出最小生成树的代价。

【输入样例】

ABCDEF!

0 1 9

0 2 10

1 2 7

1 3 5

2 4 6

2 5 7

3 4 11

4 5 8

-1

C

【输出样例】

CE 6

CB 7

BD 5

CF 7

BA 9

34

'''
#include<iostream>
using namespace std;
#include<malloc.h>
#define MAX 20
struct Mg{   
    int cost[MAX][MAX];
    int n;
    char node[MAX];
};
void InitGraph(Mg*&g)
{
    g=(Mg*)malloc(sizeof(Mg));
    int i=0,j=0;
    for(i=0;i<MAX;i++)
    {
    	for(j=0;j<MAX;j++)
    	g->cost[i][j]=999;
        g->cost[i][i]=0;
	}
    g->n=0;
}
void creatGraph(Mg *&g){
    char v;
    int i=0;
    while(1){
        scanf("%c",&v);
        if(v!='!'){
            g->node[i]=v;
            i++;
        }
        else
        break;
    }
    g->n=i;
    int a,b,c;
    while(1){
        cin>>a;
        if(a==-1)
        break;
        else{
            cin>>b>>c;
            g->cost[a][b]=g->cost[b][a]=c;
        }
    }
}
void Prim(Mg *g,int v)
{
    int i=0,j=0,k=0,sum=0;
    int lowcost[g->n];
    int closest[g->n];
    int mindist;
    for(i=0;i<g->n;i++){    
	    closest[i]=v;
        lowcost[i]=g->cost[v][i];
    }
    for(i=1;i<g->n;i++){
        mindist=999;
        for(j=0;j<g->n;j++){
            if(lowcost[j]!=0&&lowcost[j]<mindist){
                mindist=lowcost[j];
                k=j;
            }
        }
        printf("%c%c %d\n",g->node[closest[k]],g->node[k],mindist);
        sum+=mindist;
        lowcost[k]=0;
        for(j=0;j<g->n;j++){
            if(lowcost[j]!=0&&g->cost[k][j]<lowcost[j]){
                lowcost[j]=g->cost[k][j];
                closest[j]=k;
            }
        }
    }
    cout<<sum;
}
int main(){
    Mg*g;
    InitGraph(g);
    creatGraph(g);
    char n;
    cin>>n;
    int v;
    for(int i=0;i<g->n;i++){
        if(g->node[i]==n){
            v=i;
            break;
        }
    }
    Prim(g,v);
}

