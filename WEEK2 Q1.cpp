//设计算法:
//	将存有n(n>0)个数的数组A中的元素A[0]至 A[n-1]循环右移k(k>0)位
//	要求只允许使用一个元素大小的附加存储
//	元素移动或交换次数为O(n)。 

//	输入样例:
// 	 8 6
// 	 1 2 3 4 5 6 7 8
//	输出样例:
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
