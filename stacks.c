#include<stdio.h>

int stack[100];
int top = 0;

void push(int value){
	if(top>99){
		printf("\nStack Overflow\n");
		return;
	}
	stack[top] = value;
	top++;
}

int pop(){
	int value;
	printf("pop option selected\n");
	if(top<=0){
		printf("\nUnderflow Condition\n");
		return;
	}
	top--;
	value = stack[top];
	stack[top] = 0;
	return value;
}

void display(){
	int i;
	printf("display option selected\n");
	if(top==0){
		printf("null\n");
		return;
	}
	for(i=top-1;i>=0;i--){
		printf("%d ",stack[i]);
	}
	printf("\n");
}

int main(){
	int option;
	int value;
	
	while(1){
		printf("Enter the option\n1 - Push to stack\n2 - pop from stack\n3 - Display the stack\n4 - exit\n");
		scanf("%d",&option);
		if(option==4){
			return 0;
		}else{
			switch(option){
				case 1:
					printf("push option selected\n");
					scanf("%d",&value);
					push(value);
					break;
				case 2:
					value = pop();
					printf("Popped value = %d\n",value);
					break;
				case 3:
					display();
					break;
				default:
					printf("Enter the options given\n");
					break; 
			}
		}
	}
}
