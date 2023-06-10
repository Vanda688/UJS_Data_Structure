'''
【问题描述】采用除留余数法构造哈希表，并利用线性探测法解决哈希表中的冲突。H（key）=key mod p；p 取接近表长的最大素数。
【输入输出交互过程】从键盘输入表长，并输入若干整数，以-1 作为结束。建立好哈希表后，输出该哈希表及其查找成功的平均查找长度(保留至小数点后3位）；从键盘输入待查找的关键字，输出查找过程中经比较的关键字，并输出该关键字的哈希地址，并如果不存在该关键字，输出查找过程中经比较的关键字之后输出 not found。

【样例输入】

10   //表长

19 24 10 17 15 38 18 40 -1   //关键字集合

17

【样例输出】

-1 15 -1 24 10 19 17 38 18 40

ASL=3

24 10 19 17

key=6

【样例说明】
【评分标准】
'''
#include<stdio.h> 
#include<stdlib.h> 
typedef struct{
	int key;//关键字 
	int count;//探测次数 
}Hash;
/*	k:输入元素关键字 
	m:哈希表长度（质数）
	n:哈希表元素个数 
	p:哈希函数是k % p 
*/
/*void Create(Hash *&h,m){
	h=(Hash*)malloc(sizeof(Hash));
} */
void Init(Hash h[],int m){
	int i;
	for(i=0;i<m;i++){
		h[i].key=-1;
		h[i].count=0;
	}
}
int MinPrime(int &m){
	int i;
	for(i=2;i*i<=m;i++){
		if(m % i == 0){
			m--;
			return 0;
		}
	}
	return 1;
}  
void Insert(Hash h[],int &n,int m,int p,int k){
	int i,adr,cnt=0;
	adr = k%p;
	if(h[adr].key == -1){//此处为空，则插入，同时记查找次数为1 
		h[adr].key=k;
		h[adr].count=1;
	}
	else{
		cnt=1;
		do{
			adr=(adr+1)%m;
			cnt++;
		}while(h[adr].key != -1);
		h[adr].key = k;
		h[adr].count=cnt;
	} 
	//printf("!!\n");
	n++;
}
void Print(Hash h[],int m){
	int i;
	for(i=0;i<m;i++){
		printf("%d ",h[i].key);
	}
	printf("\n");
	//printf("!!\n");
}
int Search(Hash h[],int m,int p,int s,int &adr,int &cnts,int flag){
	//int adr,cnts=0;
	adr = s % p;
	while(h[adr].key!=-1&&h[adr].key!=s){
		if(flag==1){
			printf("%d ",h[adr].key);
		}
		adr=(adr+1)%m;
		cnts++;
	}
	if(h[adr].key==s){
		if(flag==1){
			printf("%d ",h[adr].key);
			printf("\nkey=%d",adr);
			return 1;
			//printf("\ncnts=%d",cnts);
		}	
	}
	if(h[adr].key==-1){
		return 0;
	}
}
int main(){
	int i,m,n=0,p,s,adr,cnts=1,flag;
	float sum=0,cnt;
	//cnt是记录元素个数，cnts是记录查找次数 flag用来控制search函数是否输出 
	scanf("%d",&m);
	p=m;
	while(!MinPrime(p)){
	}
	//printf("\nPrime=%d\n",p);
	Hash h[m];
	Init(h,m);
	int tmp[m];
	while(1){
		scanf("%d",&i);
		if(i==-1){
			break;
		}
		else{
			tmp[(int)cnt]=i;
			cnt++;
		}
	}	
	scanf("%d",&s);	
	//printf("\ncnt=%d",cnt);
	for(i=0;i<cnt;i++){
		Insert(h,n,m,p,tmp[i]);
	}
	for(i=0;i<cnt;i++){
		Search(h,m,p,tmp[i],adr,cnts,0);
		sum+=cnts;
		cnts=1;
	}
	Print(h,m);
	printf("ASL=%.3f\n",sum/cnt);
	//printf("ASL=%d",sum);
	if(!Search(h,m,p,s,adr,cnts,1)){
		printf("\nnot found");
	}
}

