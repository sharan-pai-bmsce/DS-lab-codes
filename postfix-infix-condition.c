#include<stdio.h>

char infix[100];
char postfix[100];
char stack[100];
float evaluate[100];

int top = 0;

int F(char a){
	switch(a){
		case '(':
			return 0;
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
		default:
			return 8;
	}
	return -1;
}

int G(char b){
	switch(b){
		case '(':
			return 9;
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
		default:
			return 7;
	}
	return -1;
}

void convert(){
	int i;
	int j=0;
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

void Evaluate(){
	int i;
	float op1,op2;
	for(i=0;postfix[i]!='\0';i++){
		if(postfix[i]=='0'||postfix[i]=='1'||postfix[i]=='2'||postfix[i]=='3'||postfix[i]=='4'||postfix[i]=='5'||postfix[i]=='6'||postfix[i]=='7'||postfix[i]=='8'||postfix[i]=='9'){
			evaluate[top++] = (float)(postfix[i]-'0');
		}else{
			op2 = evaluate[--top];
			op1 = evaluate[--top];
			
			switch(postfix[i]){
				case '+':
					evaluate[top++] = op1+op2;
					break;
				case '-':
					evaluate[top++] = op1-op2;
					break;
				case '*':
					evaluate[top++] = op1*op2;
					break;
				case '/':
					evaluate[top++] = op1/op2;
					break;
			}
		}
	}
}

int main(){
	gets(infix);
	int i=0;
	int flag = 0;
	for(i=0;infix[i]!='\0';i++){
		if(infix[i]=='('||infix[i]=='{'||infix[i]=='['){
			stack[top++] = infix[i];
		}else if(infix[i]==')'||infix[i]=='}'||infix[i]==']'){
			if(top-1<=-1){
				flag=1;
			}else{
				char temp = stack[--top];
				if(infix[i]==')'&&(temp=='['||temp=='{')){
					flag=1;
				}else if(infix[i]==']'&&(temp=='('||temp=='{')){
					flag=1;
				}else if(infix[i]=='}'&&(temp=='['||temp=='(')){
					flag=1;
				}
			}
		}
	}
	if(top-1!=-1){
		flag=1;
	}
	if(flag==0){
		convert();
		printf("%s\n",postfix);
			if(postfix[0]>='0'&&postfix[0]<='9'){
				Evaluate();
				printf("%f\n",evaluate[top-1]);
			}else{
				printf("Cannot be Evaluated. Kindly use numbers\n");
			}
		}else{
		printf("Invalid\n");
	}
	return 0;
}
