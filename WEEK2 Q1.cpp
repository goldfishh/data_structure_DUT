//����㷨:
//	������n(n>0)����������A�е�Ԫ��A[0]�� A[n-1]ѭ������k(k>0)λ
//	Ҫ��ֻ����ʹ��һ��Ԫ�ش�С�ĸ��Ӵ洢
//	Ԫ���ƶ��򽻻�����ΪO(n)�� 

//	��������:
// 	 8 6
// 	 1 2 3 4 5 6 7 8
//	�������:
//	 3 4 5 6 7 8 1 2 

#include<stdio.h>
void Reverse(int A[],int b,int e){
	int temp;
	for( ; b < e ; b++,e--){
		temp = A[b];
		A[b] = A[e];
		A[e] = temp;
	}
}
int main(){
//	freopen("datain","r",stdin);
	int N,K;
	scanf("%d %d",&N,&K);
	int A[N];
	for(int i = 0;i < N;i++)
		scanf("%d",&A[i]);
	K %= N;
	Reverse(A,0,N-K-1);
	Reverse(A,N-K,N-1);
	Reverse(A,0,N-1);
	for(int i = 0;i < N;i++)
		printf("%d ",A[i]);
	return 0;	
}
