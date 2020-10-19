#include<stdio.h>

#define size 5

int f=0,r=-1,value;
int q[size];

void insertRear(){
	if(r==size-1){
		printf("Queue Overflow\n");
		return;
	}
	q[++r]=value;
}

void deleteFront(){
	if(f>r){
		printf("Queue Underflow\n");
		return;
	}
	printf("deleted=%d\n",q[f++]);
	if(f>r){
		f=0;
		r=-1;
	}
}

void display(){
	if(f>r){
		printf("null\n");
		return;
	}
	int i;
	for(i=f;i<=r;i++){
		printf("%d ",q[i]);
	}
	printf("\n");
}

int main(){
	int ch;
	while(1){
		printf("\nEnter the option\n1-insert rear\n2-delete front\n3-display\n4-exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
					printf("Enter the number\n");
					scanf("%d",&value);
					insertRear(value);
				break;
			case 2:
				deleteFront();
				break;
			case 3:
				display();
				break;
			default:
				return 0;
		}
	}
}
