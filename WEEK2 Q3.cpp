//��֪K��쳲��������ж���Ϊ��
//f0 = 0,  f1 = 0, �� , fk-2 = 0, fk-1 = 1;
//fn = fn-1 + fn-2 + �� + fn-k , n = k , k + 1, ��
//����ѭ�����б�д��k��쳲�����������ǰn+1�f0, f1, f2,��, fn�����㷨
//Ҫ�����㣺fn<=max,����fn+1>max,����maxΪĳ��Լ���ĳ���
//ע�⣺��������ѭ�����е�������Ϊk�������㷨ִ�н���ʱ
//      ���ڶ����е�Ԫ��Ӧ������k��쳲����������е����k��fn-k-1 , fn-k, ��, fn

//����
//�����ʾ������k��2<=  k  <= 100���Լ���ʾĳ��������max��0 <= max <= 100000��

//��������
//4 10000
 
//�������
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
