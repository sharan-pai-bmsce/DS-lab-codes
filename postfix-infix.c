#include<stdio.h>

char infix[100];
char postfix[100];
char stack[100];

int top = 0;

int F(char a){
	switch(a){
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 4;
		case '$':
		case '^':
			return 5;
		case '#':
			return -1;
		case '(':
			return 0;
		default:
			return 8;
	}
}

int G(char b){
	switch(b){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 3;
		case '$':
		case '^':
			return 6;
		case ')':
			return 0;
		case '(':
			return 9;
		default:
			return 7;
	}
}

void convert(){
	int i,j=0;
	stack[top++] = '#';
	for(i=0;infix[i]!='\0';i++){
		while(F(stack[top-1])>G(infix[i])){
			postfix[j++] = stack[--top];
		}
		if(F(stack[top-1])!=G(infix[i])){
			stack[top++] = infix[i];
		}else{
			top--;
		}
	}
	while(stack[top-1]!='#'){
		postfix[j++] = stack[--top];
	}
	postfix[j] = '\0';
}

int main(){
	scanf("%s",infix);
	convert();
	printf("%s\n",postfix);
	return 0;
}


//x^y^z-m+n+p/q
//((a+b)*c-(d-e))^(f+g)
//a^b*c-d+e/f/(g+h)
