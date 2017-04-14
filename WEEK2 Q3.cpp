//已知K阶斐波那契数列定义为：
//f0 = 0,  f1 = 0, … , fk-2 = 0, fk-1 = 1;
//fn = fn-1 + fn-2 + … + fn-k , n = k , k + 1, …
//利用循环队列编写求k阶斐波那契数列中前n+1项（f0, f1, f2,…, fn）的算法
//要求满足：fn<=max,并且fn+1>max,其中max为某个约定的常数
//注意：本题所用循环队列的容量仅为k，则在算法执行结束时
//      留在队列中的元素应是所求k阶斐波那契序列中的最后k项fn-k-1 , fn-k, …, fn

//输入
//输入表示阶数的k（2<=  k  <= 100）以及表示某个常数的max（0 <= max <= 100000）

//输入样例
//4 10000
 
//输出样例
//17 5536  
//

#include<stdio.h>
#include<stdlib.h>
#define K_MAXSIZE 100
typedef struct QueueLP{
	int FBNQ[K_MAXSIZE];
	int rear,front;
}QueueLP,*QueueLink;
int main(){
//	freopen("datain","r",stdin);
	int K,max,f = 1,fa = 1,fm_m = 1,fm = 0,n;
	QueueLP Q;
	Q.rear = Q.front = 0;
	scanf("%d %d",&K,&max);
	n = K - 1;
	for(int i = 0; i < K-1; i++)
		Q.FBNQ[Q.front++] = 0;
	Q.FBNQ[Q.front] = 1;
	Q.front = 0;
	if(max == 0){
		printf("%d 1\n",n);
		return 0;
	} 
	while(!(max >= fa && max < f)){
		fm = Q.FBNQ[Q.rear];
		Q.rear = (Q.rear+1) % K;
		Q.FBNQ[Q.front] = f;
		Q.front = (Q.front+1) % K;
		fa = f;
		f = 2 * f - fm;
		fm_m = fm;
		n++;
	}
	printf("%d %d\n",n,fa);
	return 0;
}
