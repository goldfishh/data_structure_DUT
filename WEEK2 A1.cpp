//����ϵ������A��B������Ԫ��˳�����Ϊ�洢�ṹ�� 
//����ӷ�����   O��N+M��ʱ�临�Ӷ�   �޶���ռ�
//������Ԫ��˳���A�ռ��㹻�� 
#include<stdio.h>
#define ELEMTYPE int
#define MAXSIZE 1000
typedef struct{
	int i,j;
	ELEMTYPE p;
}Triple;
typedef struct {
	Triple data[MAXSIZE+1];
	int   mu,nu,tu;  //����,����,�ǿ�Ԫ���� 
}Matrix;
int main(){
	freopen("datain","r",stdin);
	int k , l;
	Matrix A,B;
	scanf("%d %d %d",&A.mu,&A.nu,&A.tu);
	scanf("%d %d %d",&B.mu,&B.nu,&B.tu);
	for(k = 1; k <= A.tu; k++)
		scanf("%d %d %d",&A.data[k].i,&A.data[k].j,&A.data[k].p);
	for(k = 1; k <= B.tu; k++)
		scanf("%d %d %d",&B.data[k].i,&B.data[k].j,&B.data[k].p);
	k = l = 1;
	int t = A.tu + 1;
	while(l <= B.tu && k <= A.tu){
		if(A.data[k].i > B.data[l].i || A.data[k].i == B.data[l].i && 
			A.data[k].j > B.data[l].j){
				A.data[t++] = B.data[l];
				l++;
			}
		else if(A.data[k].i < B.data[l].i || A.data[k].i == B.data[l].i && 
			A.data[k].j < B.data[l].j){
				A.data[t++] = A.data[k];
				k++;
			}
		else if(A.data[k].i == B.data[l].i && A.data[k].j == B.data[l].j ){
			if(A.data[k].p + B.data[l].p != 0){
				A.data[t].i = A.data[k].i;
				A.data[t].j = A.data[k].j;
				A.data[t].p = A.data[k].p + B.data[l].p ;
				t++,k++,l++;
			}
			else
				k++,l++;
		}		
	}
	while(l <= B.tu){
		A.data[t++] = B.data[l];
		l++;
	}
	while(k <= A.tu){
		A.data[t++] = A.data[k];
		k++;
	}
	while(k != t){
		printf("%d %d %d\n",A.data[k].i,A.data[k].j,A.data[k].p);
		k++;
    }
	//��Ӻ���Ԫ��˳����һ����Ԫ��洢��A.triple[A.tu+1] 
	return 0;
} 
