#include<stdio.h>
#define s 5
int front=0,rear=-1;
int queue[s];

void insertRear(){
	int value;
	if(rear==s-1){
		printf("Queue overflow\n");
		return;
	}
	int i,j,small;
	printf("Enter the value\n");
	scanf("%d",&value);
	queue[++rear]=value;
	if(rear>=front){
		for(i=front+1;i<=rear;i++){
			small = queue[i];//10 9 8 7 6 5
			j=i-1;
			while(j>=front&&queue[j]>small){
				queue[j+1]=queue[j];//9 9 8 7 6 5
				j--;
			}
			queue[j+1]=small;//9 10 8 7 6 5
		}
	}
}

int deleteFront(){
	if(front>rear){
		printf("Queue underflow\n");
		return -1;
	}
	int value=queue[front++];
	if(front>rear){
		front=0;
		rear=-1;
	}
	
	return value;
}

void display(){
	int i;
	if(front>rear){
		printf("Queue is empty\n");
		return;
	}
	for(i=front;i<=rear;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}

int main(){
	int ch,chq,value;
	while(1){
		printf("***Ascending Priority Queue***\n1-insert to queue\n2-delete from the front\n3-display all queue\n4-exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insertRear();
				break;
			case 2:
				value=deleteFront();
				if(value==-1){
					break;
				}else{
					printf("Deleted item:%d\n",value);
				}
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;			
		}
	}
}

/*void insertRear(){
	int value;
	if(rear==s-1){
		printf("Queue overflow\n");
		return;
	}
	int i,j,key;
	printf("Enter the value\n");
	scanf("%d",&value);
	queue[++rear]=value;
	if(rear>=1){
		for(i=1;i<=rear;i++){
			key = queue[i];
			j=i-1;
			while(j>=0&&queue[j]<key){
				queue[j+1]=queue[j];
				j--;
			}
			queue[j+1]=key;
		}
	}
}

int deleteFront(){
	if(front>rear){
		printf("Queue underflow\n");
		return -1;
	}
	int value=queue[front++];
	if(front>rear){
		front=0;
		rear=-1;
	}
	
	return value;
}

void display(){
	int i;
	if(front>rear){
		printf("Queue is empty\n");
		return;
	}
	for(i=front;i<=rear;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}

int main(){
	int ch,chq,value;
	while(1){
		printf("***Ascending Priority Queue***\n1-insert to queue\n2-delete from the front\n3-display all queue\n4-exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				insertRear();
				break;
			case 2:
				value=deleteFront();
				if(value==-1){
					break;
				}else{
					printf("Deleted item:%d\n",value);
				}
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;			
		}
	}
}
*/
