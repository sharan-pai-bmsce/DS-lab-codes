#include<stdio.h>
#include<malloc.h>

struct node{
	int num;
	struct node *next;
};

typedef struct node *NODE;

NODE getNode(){
	NODE temp = (NODE)malloc(sizeof(struct node));
	if(temp == NULL){
		return NULL;
	}
	return temp;
}

void freeNode(NODE temp){
	free(temp);
}

NODE insertFront(NODE first){
	NODE temp;
	temp = getNode();
	int num;
	scanf("%d",&num);
	temp->num = num;
	temp->next = NULL;
	if(first==NULL){
		return temp;
	}
	temp->next = first;
	first = temp;
	return first;
}

NODE deleteFront(NODE first){
	NODE temp;
	if(first==NULL){
		printf("List is empty\n");
		return NULL;
	}
	if(first->next == NULL){
		printf("Deleted element = %d\n",first->num);
		freeNode(first);
		return NULL;
	}
	temp = first;
	temp = temp->next;
	printf("Deleted elements = %d\n",first->num);
	freeNode(first);
	return temp;
}

NODE sort(NODE first){
	NODE curr,temp;
	if(first==NULL){
		return NULL;
	}
	curr = first;
	while(curr!=NULL){
		temp = curr->next;
		while(temp!=NULL){
			if(temp->num<curr->num){
				int num = curr->num;
				curr->num=temp->num;
				temp->num = num;
			}
			temp = temp->next;
		}
		curr = curr->next;
	}
	return first;
}

void display(NODE first){
	NODE curr;
	if(first==NULL){
		printf("List is empty\n");
		return;
	}
	curr = first;
	while(curr!=NULL){
		printf("%d ",curr->num);
		curr=curr->next;
	}
	printf("\n");
}

NODE reverse(NODE first){
	NODE curr=NULL;
	NODE temp = getNode();
	while(first!=NULL){
		temp = first;
		first = first->next;
		temp->next = curr;
		curr = temp;
		//printf("%d ",first->num);
	}
	return temp;
}

NODE concat(NODE first){
	NODE sec = NULL;
	int chq;
	while(1){
		printf("Enter the choice\n1-insertFront\n2-deleteFront\n3-display\n4-concat\n");
		scanf("%d",&chq);
		if(chq==4){
			break;
		}
		switch(chq){
			case 1:
				sec = insertFront(sec);
				break;
			case 2:
				sec = deleteFront(sec);
				break;
			case 3:
				display(sec);
				break;				
		}
	}
	NODE curr;
	if(first==NULL){
		return sec;
	}
	if(sec==NULL){
		return first;
	}
	curr = first;
	while(curr->next!=NULL){
		curr = curr->next;
	}
	curr->next = sec;
	return first;
}

int main(){
	int chq;
	NODE first = NULL;
	while(1){
		printf("Enter the choice\n1-insertFront\n2-deleteFront\n3-display\n4-sort\n5-reverse\n6-concat\n7-exit\n");
		scanf("%d",&chq);
		switch(chq){
			case 1:
				first = insertFront(first);
				break;
			case 2:
				first = deleteFront(first);
				break;
			case 3:
				display(first);
				break;
			case 4:
				first = sort(first);
				break;
			case 5:
				first = reverse(first);
				break;
			case 6:
				printf("Creating the second list for concat\n");
				concat(first);
				break;
			case 7:
				return 0;
			
		}
	}
}
