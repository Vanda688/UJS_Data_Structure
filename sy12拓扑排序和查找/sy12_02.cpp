'''
?????????????????????????????????A\B???????????????P69 2.17?

?????????A?B????a?b??a=b,?a??b??????????a?b??????????????????????????????????????????????????????????????????????????????????????????????

?????search(Rectype A[],Rectype B[],int n); ????A?B?????

??????Rectype ?int?

??????

?????????????-> ??????A?B->????A?B??????????->?????

??????

 ??A?B???????????

 ??????
??????

6

1 3 5 7 9 11

10 12 14 16 18 19

??????

7 9 11

10 12 14

9 11

10 12

11

10

mid=10

??????
??????
'''
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct {
    int elements[MAX];
    int length;
} Rectype;
int findMedian(int array[MAX], int length) {
    return (length % 2 == 0) ? (array[length / 2 - 1] + array[length / 2]) / 2 : array[length / 2];
}
void printArray(int array[MAX], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void search(Rectype*A, Rectype*B) {
    int len = A->length;
    int mid,i;
    while (A->elements[0] != A->elements[len-1]) {
    	if(len%2==0){
    		mid = (len/2)-1;
    		len = len/2;
    		//printf("mid=%d\n",mid);
			//printf("len=%d\n",len);
			if(A->elements[mid]==B->elements[mid]){
				break;
			}
			else if(A->elements[mid]>B->elements[mid]){
				for(i=0;i<len;i++){
					B->elements[i] = B->elements[mid+i+1];
				}
			}
			else if(A->elements[mid]<B->elements[mid]){
				for(i=0;i<len;i++){
					A->elements[i] = A->elements[mid+i+1];
				}
			}		
	        //printf("A: ");
	        printArray(A->elements,len);
	        //printf("B: ");
	        printArray(B->elements,len);
    		
		}
    	if(len%2==1&&len!=1){
    		mid = (len-1)/2;
    		len = (len+1)/2;
    		//printf("mid=%d\n",mid);
			//printf("len=%d\n",len);
			if(A->elements[mid]==B->elements[mid]){
				break;
			}
			else if(A->elements[mid]>B->elements[mid]){
				for(i=0;i<len;i++){
					B->elements[i] = B->elements[mid+i];
				}
			}
			else if(A->elements[mid]<B->elements[mid]){
				for(i=0;i<len;i++){
					A->elements[i] = A->elements[mid+i];
				}
			}		
	        //printf("A: ");
	        printArray(A->elements,len);
	        //printf("B: ");
	        printArray(B->elements,len);   		
		}
	}
	printf("mid=%d\n", (A->elements[len-1]<B->elements[len-1])?(A->elements[len-1]):(B->elements[len-1]));

}

int main() {
    int n;
    Rectype* A;
    A=(Rectype*)malloc(sizeof(Rectype));
	Rectype* B;
	B=(Rectype*)malloc(sizeof(Rectype));
    //printf("�����������\n");
    scanf("%d", &n);
    A->length = n;
    B->length = n;
    //printf("��������������A��\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A->elements[i]);
    }
    //printf("��������������B��\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &B->elements[i]);
    }
    search(A, B);
    return 0;
}


