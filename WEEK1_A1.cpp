//3个递增有序的单链表A,B,C，在A表中删除同时出现在B和C中的数据元素。
#include<stdio.h>
#include<stdlib.h>
#define Elemtype int
typedef struct NodeLL *Linklist; 
typedef struct NodeLL{
	Elemtype data;
	Linklist next;
}List;
Linklist IsDeleteNode(Linklist A,Elemtype x){
	Linklist P = (Linklist)malloc(sizeof(struct NodeLL));
	Linklist Rear = P;
	P -> next = A;
	while(A){
		if(A->data == x){
			Rear->next = A->next;
//			free(A);
			return P->next;
		}
		else{
			A = A->next;
			Rear = Rear->next;
		}
	}
}
Linklist Create_List(){
	int N,DATA;
	scanf("%d",&N);
	if(N == 0) return NULL;
	Linklist K = (Linklist)malloc(sizeof(struct NodeLL)),Rear = K;
	K->next = NULL;
	scanf("%d",&DATA);
	K->data = DATA;
	for(int i = 1;i < N;i++){
		Linklist KK = (Linklist)malloc(sizeof(struct NodeLL));
		KK->next = NULL;
		int DATAA;
		scanf("%d",&DATAA);
		KK->data = DATAA;
		Rear->next = KK;
		Rear = KK;
	}
	return K;
}
void PrintList(Linklist P){
	while(P){
		printf("%d ",P->data);
		P = P->next;
	}
}
int main(){
		freopen("datain","r",stdin);
		freopen("dataout","w",stdout);		
		Linklist A,B,C,BB,CC;
		A = Create_List();
		B = Create_List();
		C = Create_List();
		BB = B;
		while(BB){
			CC = C;
			while(CC){
				if(BB->data == CC->data){
					Elemtype x = BB->data;
					A = IsDeleteNode(A,x);
					break; 
				}	
				else
					CC = CC->next;
			}
		BB = BB->next;
		}
		PrintList(A);
//		PrintList(B);
//		PrintList(C);				
}
