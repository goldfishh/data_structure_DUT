// 从键盘读入一元多项式中每一项的系数和指数，请编写算法实现：
// 建立带表头结点的单链表存放一元多项式（按照指数升序排列）；
// 输出一元多项式的所有数据元素；
// 将单链表存放的一元多项式就地逆置，变成按照指数降序排列；
// 输入自变量的值，计算一元多项式的值；
// 求2个一元多项式的和多项式；

// *附加题：3个递增有序的单链表A,B,C，在A表中删除同时出 现在B和C中的数据元素。
// **选作：使用文本菜单完成功能选择及执行。

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef struct PolyNode *Polynomial;
struct PolyNode{
	int coef;   //系数 
	int expon;  //指数 
	Polynomial link;
}; 
//输入样例:   N(多项式项数) coef1 expon1 coed2 expon2 ...... 
Polynomial ReadPoly(){
	Polynomial P,S,Rear;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P -> link = NULL;
	Rear = P;
	int N,c,e;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&c,&e);
//		Attach(c,e,&Rear);
		S = (Polynomial)malloc(sizeof(struct PolyNode));
		S -> link = NULL;
		S -> coef = c; S -> expon = e;
		Rear -> link = S;
		Rear = S;
	}
	S = P ; P = P -> link; free(S);
	return P;
}

//倒置多项式链表 
//!!!!!!!!!!!!!!注意:倒置链表会把原链表结构破坏掉 
Polynomial Disorder(Polynomial P){
	Polynomial P1,P2,PP;
	P1 = (Polynomial)malloc(sizeof(struct PolyNode));
	P1 -> link = P;
	P2 = P1 -> link -> link;
	P1 -> link -> link = NULL; 
	while(P2){
		PP = P2 -> link;
		P2 -> link = P1 -> link;
		P1 -> link = P2;
		P2 = PP;
	}
	P = P1 -> link;
	free(P1);free(P2);free(PP);
	return P;
} 
long long x_input(int x,Polynomial P){
	long long sum = 0;
	while(P){
		sum += (P ->coef * pow(x,P->expon));
		P = P -> link; 
	}
	return sum;
}


//多项式相乘 
Polynomial Mult(Polynomial P1,Polynomial P2){
	Polynomial P,PP,Rear,RearRear,p1,p2,S;
	p1 = P1;p2 = P2;
	if(!p1 || !p1) return NULL;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P -> link = NULL;
	Rear = P;
	while(p2){
		S = (Polynomial)malloc(sizeof(struct PolyNode));
		S->coef = p1->coef * p2->coef;
		S->expon = p1->expon + p2->expon;
		S->link = NULL;
		Rear -> link = S;
		Rear = S;
//		p1 = p1 -> link;
		p2 = p2 -> link;  		
	}
	S = P ; P = P -> link; free(S);
	p1 = p1 -> link;
	while(p1){
		PP = (Polynomial)malloc(sizeof(struct PolyNode));
		PP -> link = NULL;
		RearRear = PP;
		p2 = P2;
		while(p2){
			S = (Polynomial)malloc(sizeof(struct PolyNode));
			S->coef = p1->coef * p2->coef;
			S->expon = p1->expon + p2->expon;
			S->link = NULL;
			RearRear -> link = S;
			RearRear = S;
	//		p1 = p1 -> link;
			p2 = p2 -> link;  		
		}
		S = PP;PP = PP->link;free(S);
		Polynomial Add(Polynomial P1,Polynomial P2);
		P = Add(P,PP);
		p1 = p1 -> link;
	}
	return P;
}
//多项式相加 
Polynomial Add(Polynomial P1,Polynomial P2){
	Polynomial P,Rear,p1,p2,S;
	p1 = P1;p2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P -> link = NULL;
	Rear = P;
	while(p1 && p2){
		if(p1->expon == p2->expon){
			if(p1->coef + p2->coef ==0){
				p1 = p1 -> link;
				p2 = p2 -> link;
			}
			else{
				S = (Polynomial)malloc(sizeof(struct PolyNode));
				S->coef = p1->coef + p2->coef;
				S->expon = p1->expon;
				S->link = NULL;
				Rear -> link = S;
				Rear = S;
				p1 = p1 -> link;
				p2 = p2 -> link;  
			}
		}
		else if(p1->expon > p2->expon){
			S = (Polynomial)malloc(sizeof(struct PolyNode));
			S->coef = p1->coef;
			S->expon = p1->expon;
			S->link = NULL;
			Rear -> link = S;
			Rear = S;
			p1 = p1 -> link;
//			p2 = p2 -> link;
		}
		else {
			S = (Polynomial)malloc(sizeof(struct PolyNode));
			S->coef = p2->coef;
			S->expon = p2->expon;
			S->link = NULL;
			Rear -> link = S;
			Rear = S;
//			p1 = p1 -> link;
			p2 = p2 -> link;
		}
	}
	while(p1){
		S = (Polynomial)malloc(sizeof(struct PolyNode));
		S->coef = p1->coef;
		S->expon = p1->expon;
		S->link = NULL;
		Rear -> link = S;
		Rear = S;
		p1 = p1 -> link;
//		p2 = p2 -> link;	
	}
	while(p2){
		S = (Polynomial)malloc(sizeof(struct PolyNode));
		S->coef = p2->coef;
		S->expon = p2->expon;
		S->link = NULL;
		Rear -> link = S;
		Rear = S;
//		p1 = p1 -> link;
		p2 = p2 -> link;	
	}	
	S = P;P = P->link;free(S);
	return P;
}
//打印多项式 
void PrintPoly(Polynomial P){
	bool flag = false;
	if(!P){
		 printf("0 0\n");
		 return ;
	}
	Polynomial Rear = P;
	while(Rear){
		if(!flag){
			flag = true;
		}
		else
			printf(" ");
		printf("%d %d",Rear->coef,Rear->expon);
		Rear = Rear -> link;
	}
	printf("\n");
}
int main(){
	freopen("datain","r",stdin);
	freopen("dataout","w",stdout);
	Polynomial P1,P2,PP,PS;
	while(1){
		cout << "1  读入第一个多项式" <<endl;
		cout << "2  读入第二个多项式" <<endl;
		cout << "3  输出多项式" <<endl;
		cout << "4  倒置指定多项式" <<endl;
		cout << "5  多项式加法运算" <<endl;
		cout << "6  多项式乘法运算" <<endl;
		cout << "7  指定自变量x求和" <<endl;
		cout << "0  我算完了 要离开" <<endl;
		int j;
		cin >> j;
		if(j == 0)
			break;
		else if(j == 1){
			P1 = ReadPoly();
		}
		else if(j == 2){
			P2 = ReadPoly();			
		}
		else if(j == 3){
			cout << "你要输出哪一个多项式？第一个还是第二个？或是加法乘法运算后的多项式？请用数字1、2、3、4选择，否则将返回主菜单" << endl;
			int k;
			cin >> k;
			if(k == 1)
				PrintPoly(P1);	 
			else if(k == 2)
				PrintPoly(P2);
		}
		else if(j == 4) {
			cout << " 你要倒置哪一个多项式？第一个还是第二个？请用数字1和2选择，否则将返回主菜单" << endl;
			int k;
			cin >> k;
			if(k == 1)
				P1 = Disorder(P1);	 
			else if(k == 2)
				P2 = Disorder(P2);
			else if(k == 3)
				PP = Disorder(PP);
			else if(k == 4)
				PS = Disorder(PS);								
		}
		else if(j ==5){
			PP = Add(P1,P2);
			cout << "运算完毕，加法运算后的多项式储存在第3个多项式中" <<endl;
			PrintPoly(PP);
		} 
		else if(j == 6) {
			PS = Mult(P1,P2);
			cout << "运算完毕，加法运算后的多项式储存在第4个多项式中" <<endl;
			PrintPoly(PS);
		}
		else if(j == 7) {
			cout << " 你要选择哪一个多项式？请用数字1、2、3、4选择，否则将返回主菜单" << endl;
			int t;
			cin >> t; 
			cout << "请输入x值，注意结果大小不能超过long long能存储的极限" <<endl;
			int x;
			cin >> x;
			if(t == 1)
				printf("%lld\n",x_input(x,P1));
			if(t == 2)
				printf("%lld\n",x_input(x,P2));
			if(t == 3)
				printf("%lld\n",x_input(x,PP));
			if(t == 4)
				printf("%lld\n",x_input(x,PS));
		}
		cout << "是否退出？1  是  2 返回主菜单\n";
		int e;cin >> e;
		if(e == 1) break;
		else continue;
	} 
//	cout << "请输入要运算多项式的相关信息：其中N代表该一元多项式有N项、coef1 expon1代表第一项系数和指数，以此类推......N coef1 expon1 coef2 expon2"

//	P2 = Disorder(P1);


//	printf("%lld\n",x_input(8,P1));
///	printf("%lld\n",x_input(2,P2));
//	PrintPoly(P1);
//	P2 = ReadPoly();
//	PrintPoly(P2);
//	PrintPoly(P1);
//	PrintPoly(P2);
//	PrintPoly(PP);
//	PS = Add(P1,P2);
//	PrintPoly(P1);
//	PrintPoly(P2);	
//	PrintPoly(PS);
	return 0;
}
