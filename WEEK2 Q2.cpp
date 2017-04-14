//	���ʽ�ɵ���ĸ������˫Ŀ������������������͡� �������
//	����㷨����ʽ���沨��ʽ�� 

//	��������:
//	a*(b/(c-d)+e)-f

//	�������:
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
