// �Ӽ��̶���һԪ����ʽ��ÿһ���ϵ����ָ�������д�㷨ʵ�֣�
// ��������ͷ���ĵ�������һԪ����ʽ������ָ���������У���
// ���һԪ����ʽ����������Ԫ�أ�
// ���������ŵ�һԪ����ʽ�͵����ã���ɰ���ָ���������У�
// �����Ա�����ֵ������һԪ����ʽ��ֵ��
// ��2��һԪ����ʽ�ĺͶ���ʽ��

// *�����⣺3����������ĵ�����A,B,C����A����ɾ��ͬʱ�� ����B��C�е�����Ԫ�ء�
// **ѡ����ʹ���ı��˵���ɹ���ѡ��ִ�С�

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef struct PolyNode *Polynomial;
struct PolyNode{
	int coef;   //ϵ�� 
	int expon;  //ָ�� 
	Polynomial link;
}; 
//��������:   N(����ʽ����) coef1 expon1 coed2 expon2 ...... 
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

//���ö���ʽ���� 
//!!!!!!!!!!!!!!ע��:����������ԭ����ṹ�ƻ��� 
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


//����ʽ��� 
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
//����ʽ��� 
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
//��ӡ����ʽ 
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
		cout << "1  �����һ������ʽ" <<endl;
		cout << "2  ����ڶ�������ʽ" <<endl;
		cout << "3  �������ʽ" <<endl;
		cout << "4  ����ָ������ʽ" <<endl;
		cout << "5  ����ʽ�ӷ�����" <<endl;
		cout << "6  ����ʽ�˷�����" <<endl;
		cout << "7  ָ���Ա���x���" <<endl;
		cout << "0  �������� Ҫ�뿪" <<endl;
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
			cout << "��Ҫ�����һ������ʽ����һ�����ǵڶ��������Ǽӷ��˷������Ķ���ʽ����������1��2��3��4ѡ�񣬷��򽫷������˵�" << endl;
			int k;
			cin >> k;
			if(k == 1)
				PrintPoly(P1);	 
			else if(k == 2)
				PrintPoly(P2);
		}
		else if(j == 4) {
			cout << " ��Ҫ������һ������ʽ����һ�����ǵڶ�������������1��2ѡ�񣬷��򽫷������˵�" << endl;
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
			cout << "������ϣ��ӷ������Ķ���ʽ�����ڵ�3������ʽ��" <<endl;
			PrintPoly(PP);
		} 
		else if(j == 6) {
			PS = Mult(P1,P2);
			cout << "������ϣ��ӷ������Ķ���ʽ�����ڵ�4������ʽ��" <<endl;
			PrintPoly(PS);
		}
		else if(j == 7) {
			cout << " ��Ҫѡ����һ������ʽ����������1��2��3��4ѡ�񣬷��򽫷������˵�" << endl;
			int t;
			cin >> t; 
			cout << "������xֵ��ע������С���ܳ���long long�ܴ洢�ļ���" <<endl;
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
		cout << "�Ƿ��˳���1  ��  2 �������˵�\n";
		int e;cin >> e;
		if(e == 1) break;
		else continue;
	} 
//	cout << "������Ҫ�������ʽ�������Ϣ������N�����һԪ����ʽ��N�coef1 expon1�����һ��ϵ����ָ�����Դ�����......N coef1 expon1 coef2 expon2"

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
