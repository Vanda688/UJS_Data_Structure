'''
���������������ó��������������ϣ������������̽�ⷨ�����ϣ���еĳ�ͻ��H��key��=key mod p��p ȡ�ӽ��������������
����������������̡��Ӽ����������������������������-1 ��Ϊ�����������ù�ϣ�������ù�ϣ������ҳɹ���ƽ�����ҳ���(������С�����3λ�����Ӽ�����������ҵĹؼ��֣�������ҹ����о��ȽϵĹؼ��֣�������ùؼ��ֵĹ�ϣ��ַ������������ڸùؼ��֣�������ҹ����о��ȽϵĹؼ���֮����� not found��

���������롿

10   //��

19 24 10 17 15 38 18 40 -1   //�ؼ��ּ���

17

�����������

-1 15 -1 24 10 19 17 38 18 40

ASL=3

24 10 19 17

key=6

������˵����
�����ֱ�׼��
'''
#include<stdio.h> 
#include<stdlib.h> 
typedef struct{
	int key;//�ؼ��� 
	int count;//̽����� 
}Hash;
/*	k:����Ԫ�عؼ��� 
	m:��ϣ���ȣ�������
	n:��ϣ��Ԫ�ظ��� 
	p:��ϣ������k % p 
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
	if(h[adr].key == -1){//�˴�Ϊ�գ�����룬ͬʱ�ǲ��Ҵ���Ϊ1 
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
	//cnt�Ǽ�¼Ԫ�ظ�����cnts�Ǽ�¼���Ҵ��� flag��������search�����Ƿ���� 
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

