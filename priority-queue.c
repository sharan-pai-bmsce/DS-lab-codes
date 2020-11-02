#include<stdio.h>
#define r 3
#define c 3
int a[r][c];
int front[r]={0,0,0},rear[r]={-1,-1,-1};
void insertRear(int chq){
	int value;
	if(rear[chq-1]==c-1){
		printf("Queue Overflow\n");
		return;
	}
	printf("Enter the value\n");
	scanf("%d",&value);
	rear[chq-1]=rear[chq-1]+1;
	a[chq-1][rear[chq-1]]=value;
}

int deleteFront(){
	int i;
	for(i=0;i<r;i++){
		if(front[i]>rear[i]){
			printf("Queue-%d  is empty\n",i+1);
			front[i]=0;
			rear[i]=-1;
		}else{
			return 	a[i][front[i]++];
		}
	}
	return -1;
}

void display(){
	int i,j;
	for(i=0;i<3;i++){
		if(front[i]>rear[i]){
			printf("Queue-%d is empty\n",i+1);
		}else{
			printf("Queue-%d: ",i+1);
			for(j=front[i];j<=rear[i];j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
}

int main(){
	int ch,chq,value;
	while(1){
		printf("***Priority Queue***\n1-insert to queue\n2-delete from the front\n3-display all queue\n4-exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the queue number\n");
				scanf("%d",&chq);
				insertRear(chq);
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

