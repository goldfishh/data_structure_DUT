//	表达式由单字母变量和双目四则运算符及“（”和“ ）”组成
//	设计算法求表达式的逆波兰式。 

//	输入样例:
//	a*(b/(c-d)+e)-f

//	输出样例:
//	 abcd-/e+*f-

#include<stdio.h>
#define MAXSIZE 30
int main(){
//	freopen("datain","r",stdin);
	char Initial[MAXSIZE] = {0};
	scanf("%s",Initial);
	char K[MAXSIZE]={0};
	int top = -1,i = 0;
	while(Initial[i] != 0 || top != -1){
		if(Initial[i] >= 'a' && Initial[i] <= 'z' || Initial[i] >= 'A' && Initial[i] <='Z')
			printf("%c",Initial[i]);
		else if(Initial[i] == '(')
			K[++top] = Initial[i];
		else if(Initial[i] == '+' || Initial[i] == '-'){
			if(top == -1 || K[top] == '(')  K[++top] = Initial[i];
			else if(K[top] == '+' || K[top] == '-' || K[top] == '/' || K[top] == '*'){
				printf("%c",K[top]);
				top--;
				K[++top] = Initial[i];
			}
		}
		else if(Initial[i] == '*' || Initial[i] == '/'){
			if(top == -1 || K[top] == '(')  K[++top] = Initial[i];
			else if(K[top] == '+' || K[top] == '-')
				printf("%c",Initial[i]);
			else if(K[top] == '/' || K[top] == '*'){
				printf("%c",K[top]);
				top--;
				K[++top] = Initial[i];
			}
		}
		else if(Initial[i] == ')'){
			if(K[top] != '('){
				printf("%c",K[top]);
				top--;
			}
			top--;
		}
		else{
			printf("%c",K[top]);
			top--;
		}
		i++;
	}
	return 0;
}
