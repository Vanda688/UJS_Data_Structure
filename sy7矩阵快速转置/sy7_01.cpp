'''
�������������Ӽ������������С��кͷ���Ԫ�ظ������Լ����������ݣ��ֱ��ʾϵ���������Ԫ�ص��С��к�ֵ��������Ԫ����Ӧ����Ϣ��Ϊ�˱��ڹ۲������뽫����Ԫ����е�ÿ����¼����ֵ��Ϊ0���ٿ�ʼ��ɾ���Ŀ���ת�ã�������������ʾ��˳�������Ӧ������
��������ʽ�� 

  ����m ����n ����Ԫ�ظ���t

  t������

�������ʽ��

   ����������ʽ�������Ԫ����ʾ�ľ���

   �������ת�ú�ÿ�е�һ������Ԫ�����µ���Ԫ����е��±ꣻ

   ���ݿ���ת���㷨����ת�ã������3����¼������µ���Ԫ���

   ����������ʽ���ת��֮��ľ���

���������롿

   6 7 8

   0 1 12

   0 2 9

   2 0 3

   2 5 1

   3 2 24

   4 1 18

   5 0 5 

   5 3 7
����������� 

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





������˵����
�����ֱ�׼��
'''
#include<stdio.h>
#define Max 50
typedef struct{
	int r,c,d;//�� �� ֵ 
}TupNode;//��Ԫ������ 
typedef struct{
	int r,c,n;//�� �� Ԫ�ظ��� 
	TupNode data[Max];
}TSMatrix;//��Ԫ������ 
void printMat(TSMatrix t){
	int m,n,k=0;//m��n�� ,kΪ��Ԫ�����,��0��ʼ���� 
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
		int i2=0;//i2ΪԪ��������Ԫ����±� 
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

