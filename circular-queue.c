#include<stdio.h>
#define size 5
int count=0,rear=0,front=0;
int q[size];

void insertRear(int value){
	if(count==size){
		printf("Queue Overflow\n");
		return;
	}
	rear%=size;
	q[rear++]=value;
	count++;
}

void deleteRear(){
	if(count==0){
		printf("Queue Underflow\n");
		return;
	}
	printf("Deleted=%d\n",q[front++]);
	front%=size;
	count--;
}

void display(){
	if(count==0){
		printf("null\n");
		return;
	}
	int i,f=front;
	for(i=0;i<count;i++){
		printf("%d ",q[f++]);
		f%=size;
	}
	printf("\n");
}

int main(){
	int ch,value;
	while(1){
		printf("\nEnter the option\n1-insert rear\n2-delete front\n3-display\n4-exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				if(count!=size){
					printf("Enter the number\n");
					scanf("%d",&value);
					insertRear(value);
				}else{
					printf("null\n");
				}
				break;
			case 2:
				deleteRear();
				break;
			case 3:
				display();
				break;
			default:
				return 0;
		}
	}
}
