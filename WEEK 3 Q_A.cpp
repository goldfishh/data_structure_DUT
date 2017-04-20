#include<stdio.h>
#define ELETYPE int 
#define MAXSIZE 100
typedef struct NodeBT *Tree;
typedef struct NodeCBBT *Tree;
typedef struct NodeBT{
	ELETYPE data;
	Tree lc,rc;
	int visit;
};
typedef struct NodeCBBT{
	ELETYPE data;
	Tree fchild,sibling;
};
void InOrderTravesal(Tree BT){
	Tree T = BT;
	Tree Stack[MAXSIZE],top = -1;
	while(T || top != -1){
		while(T){
			Stack[++top] = T;
			printf("%d",T->data);
			T = T->lc;
		}
		if(top != -1){
			T = Stack[top--];
			T = T-> Right;
		}
	}
}
void PostOrderTravesal(Tree BT){
	Tree T = BT;
	int FLOOR[6] = {0};
	int Stack[MAXSIZE].top = -1;
	while(T || top != -1){
		while(T){
			if(T->visit == 0){
				T->visit++;
				Stack[++top] = T;
			}
			T = T->lc;
		}
		if(top != -1){
			T = Stack[top];
			if(T->visit == 2){
				if(T->lc && T->rc)
					T->data = T->lc->data + T->rc->data + 1;
				FLOOR[T->data]++;
				T = NULL;
			}
			else{
				T->visit++;
				Stack[++top] = T;
				T = T->rc;
			}
		}
	}
}

void InOrderTravesal(Tree BT){
	int count = 0; 
	Tree T = BT;
	Tree Stack[MAXSIZE],top = -1;
	while(T || top != -1){
		while(T){
			Stack[++top] = T;
			if(T->lc == NULL && T->rc == NULL || T-> lc == NULL && T->rc != NULL)
				count++;
			T = T->lc;
		}
		if(top != -1){
			T = Stack[top--];
			T = T-> Right;
		}
	}
} 

void IsCompleteTree(Tree BT){
	Tree Queue[MAXSIZE]
	int rear,front,flag = 0;
	rear = front = 0;
	Tree T = BT;
	Queue[front++] = T;
	while(rear != front){
		Tree TT = Queue[rear++];
		if(TT->lc && flag == 0)
			Queue[front++] = TT->lc;
		else if(TT->lc == NULL && flag == 0)
			flag = 1;
		else{
			printf("No\n");
			return ;
		}
		if(TT->rc && flag == 0)
			Queue[front++] = TT->rc;
		else(TT->rc == NULL && flag == 0)
			flag = 1;
		else{
			printf("No\n");
			return ;
		}
	}
	printf("Yes\n");
}

int InOrderTravesal(Tree BT){
	Tree T = BT;
	int max_floor = 0;
	Tree Stack[MAXSIZE],top = -1;
	while(T || top != -1){
		while(T){
			Stack[++top] = T;
			
			T = T->lc;
		}
		if(top != -1){
			T = Stack[top--];
			T = T->rc;
		}
	}
	return max_floor;
}
int main(){
	freopen("datain","r",stdin);
	
	return 0;
}
