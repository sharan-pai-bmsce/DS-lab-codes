#include<stdio.h>
#define size 5
int f=0,r=-1,q[size];
int value;
void insertRear(){
	if(r==size-1){
		printf("Queue overflow\n");
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
void insertFront(){
	if(f!=0){
		q[--f]=value;
		return;
	}
	else if((f==0)&&(r==-1)){
		q[++r]=value;
		return;
	}
	else
		printf("Insertion not possible\n");
}

void deleteRear(){
	if(r<f){
		printf("Queue underflow\n");
		return;
	}
	printf("deleted=%d\n",q[r--]);
	if(f>r){
		f=0;
		r=-1;
	}
}

void display(){
	int i=0;
	if(r<f){
		printf("null\n");
		return;
	}
	for(i=f;i<=r;i++){
		printf("%d ",q[i]);
	}
	printf("\n");
}

int main(){
	int ch;
	while(1){
		printf("\nEnter the option\n1-insert rear\n2-delete front\n3-insert front\n4-delete rear\n5-display\n6-exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the number\n");
				scanf("%d",&value);
				insertRear();
				break;
			case 2:
				deleteRear();
				break;
			case 3:
				printf("Enter the number\n");
				scanf("%d",&value);
				insertFront();
				break;
			case 4:
				deleteFront();
				break;
			case 5:
				display();
				break;
			default:
				return 0;
		}
	}
}
