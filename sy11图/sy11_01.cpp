'''
【问题描述】

 1. 从键盘输入一串字符，表示若干个顶点的信息

 2. 输入若干个字符对和一个整数，分别表示弧尾、弧头和权值，以#作为输入结束

3.  输入一个顶点信息

4.  求出该顶点到其余各顶点的最短路径。
【输入形式】

ABCDEFGH

AB 6

AD 1

AF 50

BC 43

BD 11

BE 6

CH 8

DE 12

EC 38

EG 24

FE 1

FG 12

GH 20

#

A
【输出形式】

AD 1

AB 6

AE 12

AG 36

AC 49

AF 50

AH 56
'''
#include<iostream>
using namespace std;
#include<malloc.h>
#define Max 20
struct Mg{
    char vertex[Max];
    int edges[Max][Max];
    int n; 
};
void Init(Mg*&g){
    int i=0,j=0;
    g=(Mg*)malloc(sizeof(Mg));
    for(;i<Max;i++){
        for (j = 0; j < Max; j++) {
            g->edges[i][j]=999;
        }
        g->edges[i][i]=0;
	}
    g->n=0;
}
void Print(Mg* g) {
    int i = 0, j;
    for (; i < g->n; i++) {
        for (j = 0; j < g->n; j++) {
            printf("%d ", g->edges[i][j]);
        }
        printf("\n");
    }
}
void Create(Mg *&g){
    char v;
    int i=0;
    while(1){
        scanf("%c",&v);
        if(v!='\n'){
            g->vertex[i]=v;
            i++;
        }
        else
        break;
    }
    g->n=i;
    int a,b,c;
    char x,y;
    while(1){
        cin>>x;
        if(x=='#')
        break;
        else{
            for(int k=0;k<g->n;k++){
                if(g->vertex[k]==x)
                a=k;
            }
            cin>>y;
            for(int k=0;k<g->n;k++){
                if(g->vertex[k]==y)
                b=k;
            }
            cin>>c;
            g->edges[a][b]=c;
        }
    }
}
void Dispath(Mg *g,int dis[],int v){
    int i,j,k;
    int visited[g->n];
    for(i=0;i<g->n;i++){
        visited[i]=0;
    }
    visited[v]=1;
    for(i=1;i<g->n;i++){
        int min=999;
        for(j=0;j<g->n;j++){
            if(min>dis[j]&&visited[j]!=1){
                min=dis[j];
                k=j;
            }
        }
        visited[k]=1;
        printf("%c%c %d\n",g->vertex[v],g->vertex[k],dis[k]);
    }
}
void Djst(Mg*g,int v){
    int dis[Max],path[Max],s[Max];
    int mindist,i,j,u;
    for(i=0;i<g->n;i++){
        dis[i]=g->edges[v][i];
        s[i]=0;
        if (dis[i] < 999) {
            path[i]=v;
        }
        else {
            path[i]=-1;
        }
    }
    s[v]=1;path[v]=0;
    for(i=0;i<g->n-1;i++){
        mindist=999;
        for(j=0;j<g->n;j++){
            if(s[j]==0&&dis[j]<mindist){
                u=j;
                mindist=dis[j];
            }
        }
        s[u]=1;
            for(j=0;j<g->n;j++){
                if(s[j]==0){
                    if(g->edges[u][j]<999&&dis[u]+g->edges[u][j]<dis[j]){
                        dis[j]=dis[u]+g->edges[u][j];
                        path[j]=u;
                    }
                }
            }
        }
    Dispath(g,dis,v);
}
int main (){
    Mg*g;
    char n;
    int v;
    Init(g);
    Create(g);
    cin>>n;
    for(int i=0;i<g->n;i++){
        if(g->vertex[i]==n){
            v=i;
            break;
        }
    }
    Djst(g,v);
    return 0;
}

