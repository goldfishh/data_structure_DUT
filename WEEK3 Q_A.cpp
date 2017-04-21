#include<stdio.h>
#define ELETYPE int 
#define MAXSIZE 100
typedef struct NodeBT *Tree;
typedef struct NodeCSBT *BSTree;
struct NodeBT{
	ELETYPE data;
	Tree lc,rc;
	int visit;
};
struct NodeCSBT{
	ELETYPE data;
	BSTree fchild,sibling;
	int visit;
};
int N;
BSTree Create_BSTree(){
	int i, N;
	scanf("%d",&N);
	if(N == 0){
		printf("The tree is blank!\n");
		return NULL;
	}
	BSTree T[N];
	struct NodeCSBT TT[N];
	for(i = 0; i < N; i++)
		T[i] = &TT[i];
	T[0]->fchild = &TT[1];
	T[0]->sibling = NULL;
	T[1]->fchild = &TT[4];
	T[1]->sibling = &TT[2];
	T[2]->fchild = &TT[5];
	T[2]->sibling = &TT[3];
	T[3]->fchild = &TT[6];
	T[3]->sibling = NULL;
	T[4]->fchild = NULL;
	T[4]->sibling = NULL;
	T[5]->fchild = NULL;
	T[5]->sibling = NULL;
	T[6]->fchild = NULL;
	T[6]->sibling = &TT[7];
	T[7]->fchild = NULL;
	T[7]->sibling = NULL;
	for(i = 0; i < N; i++)
		T[i]->data = i;		
	for(i = 0; i < N; i++)
		T[i]->visit = 0;
	return T[0];
}
Tree Create_Tree(){
	int i;
	scanf("%d",&N);
	if(N == 0){
		printf("The tree is blank!\n");
		return NULL;
	}
	Tree T[N];
	struct NodeBT TT[N];
	for(i = 0; i < N; i++)
		T[i] = &TT[i];
	T[0]->lc = &TT[1];
	T[0]->rc = &TT[2];
	T[1]->lc = &TT[3];
	T[1]->rc = &TT[4];
	T[2]->lc = &TT[5];
	T[2]->rc = &TT[6];
	T[3]->lc = NULL;
	T[3]->rc = &TT[7];
	T[4]->lc = NULL;
	T[4]->rc = NULL;
	T[5]->lc = NULL;
	T[5]->rc = NULL;
	T[6]->lc = NULL;
	T[6]->rc = NULL;
	T[7]->lc = NULL;
	T[7]->rc = NULL;
	for(i = 0; i < N; i++)
		T[i]->data = i;
	for(i = 0; i < N; i++)
		T[i]->visit = 0;		
	return T[0];
}
//第一题:实现二叉树先序遍历的非递归算法 
void InOrderTravesal(Tree BT){
	Tree T = BT;
	Tree Stack[MAXSIZE];
	int top = -1;
	while(T || top != -1){
		while(T){
			Stack[++top] = T;
			printf("%d",T->data);
			T = T->lc;
		}
		if(top != -1){
			T = Stack[top--];
			T = T->rc;
		}
	}
	printf("\n");
}
//第二题:设计非递归算法求二叉树的高 
//此处结点data存的是该节点对应树的深度 
void TreeHeight(Tree BT){
	Tree T = BT;
	int FLOOR[6] = {0};
	Tree Stack[MAXSIZE];
	int top = -1;
	while(T || top != -1){
		while(T){
			if(T->visit == 0){
				T->visit++;
				T->data = 1;
				Stack[++top] = T;
			}
			T = T->lc;
		}
		if(top != -1){
			T = Stack[top--];
			if(T->visit == 2){
				if(T->lc && T->rc)
					if(T->lc->data > T->rc->data) 
					 	T->data = T->lc->data  + 1;
					else
						T->data = T->rc->data  + 1;
				else if(T->lc == NULL && T->rc != NULL)
					T->data = T->rc->data + 1;
				else if(T->lc != NULL && T->rc == NULL)
					T->data = T->lc->data + 1;
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
	printf("The Height is %d\n",BT->data);
//	int count = 0;
//	for(int i = 0; i < 6; i++)
//		if(FLOOR[i] != 0 && count < N){
//			count += FLOOR[i];
//			printf("%d floor has %d nodes\n",i+1,FLOOR[i]);
//		}
}
//第三题:设计非递归算法求二叉树所对应的森林中的叶子结点数 
void TreeLeavesNum(Tree BT){
	int count = 0; 
	Tree T = BT;
	Tree Stack[MAXSIZE];
	int top = -1;
	while(T || top != -1){
		while(T){
			Stack[++top] = T;
			if(T->lc == NULL && T->rc == NULL || T-> lc == NULL && T->rc != NULL)
				count++;
			T = T->lc;
		}
		if(top != -1){
			T = Stack[top--];
			T = T-> rc;
		}
	}
	printf("Tree Leaves Num Is:%d\n",count);
} 
//第四题:判断一个二叉树是否为完全二叉树 
void IsCompleteTree(Tree BT){
	Tree Queue[MAXSIZE];
	int rear,front,flag = 0,mark = 0,FLOOR[8]={0};
	rear = front = 0;
	Tree T = BT;
	T->data = 0;
	FLOOR[T->data]++;;
	Queue[front++] = T;
	while(rear != front){
		Tree TT = Queue[rear++];
		if(TT->lc && flag == 0){
			Queue[front++] = TT->lc;
			TT->lc->data = TT->data + 1;
			FLOOR[TT->data + 1]++;
		}
		else if(TT->lc == NULL && flag == 0)
			flag = 1;
		else if(TT->lc && flag == 1){
			printf("No\n");
			TT->lc->data = TT->data + 1;
			FLOOR[TT->data + 1]++;
			mark = 1;
		}
		if(TT->rc && flag == 0){
			Queue[front++] = TT->rc;
			TT->rc->data = TT->data + 1;
			FLOOR[TT->data + 1]++;
		}			
		else if(TT->rc == NULL && flag == 0)
			flag = 1;
		else if(TT->rc && flag == 1){
			printf("No\n");
			TT->rc->data = TT->data + 1;
			FLOOR[TT->data + 1]++;
			mark = 1;
		}
	}
	if(mark == 0) 
		printf("Yes\n");
		
	int count = 0;
	for(int i = 0; i < 8; i++)
		if(FLOOR[i] != 0 && count < N){
			count += FLOOR[i];
			printf("%d floor has %d nodes\n",i+1,FLOOR[i]);
		}
	return ;
}
//附加题:设树采用孩子兄弟表示法存放.用类C语言设计算法计算树的高度 
void TreeHeight_CSTree(BSTree BT){
	BSTree T = BT;
	BSTree Stack[MAXSIZE];
	int top = -1;
	while(T || top != -1){
		while(T){
			if(T->visit == 0){
				T->visit++;
				T->data = 1;
				Stack[++top] = T;
			}
			T = T->fchild;
		}
		if(top != -1){
			T = Stack[top--];
			if(T->visit == 2){
				if(T->fchild && T->sibling)
					if(T->sibling->data > T->fchild->data+1)
						T->data = T->sibling->data;
					else
						T->data = T->fchild->data+1;
				else if(T->fchild == NULL && T->sibling != NULL)
					T->data = T->sibling->data;
				else if(T->fchild != NULL && T->sibling == NULL)
					T->data = T->fchild->data + 1;
				T = NULL;
			}
			else{
				T->visit++;
				Stack[++top] = T;
				T = T->sibling;
			}
		}
	}
	printf("The Height is %d\n",BT->data);
}
int main(){
	freopen("datain","r",stdin);
	Tree A = Create_Tree();
	if(!A) return 0;
	InOrderTravesal(A);
	TreeHeight(A);
	TreeLeavesNum(A);
	IsCompleteTree(A);
	
	BSTree B = Create_BSTree();
	if(!B) return 0;
	TreeHeight_CSTree(B);
	return 0;
}
