#include<stdio.h>
#include<malloc.h>
struct node{
	int value;
	struct node *next;
};

typedef struct node *NODE;

NODE getNode(){
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	if(temp == NULL){
		printf("Memory is full\n");
		return NULL;
	}
	return temp;
}

void freeNode(NODE temp){
	free(temp);
}

NODE insertFront(NODE first){
	int num;
	printf("Enter the number\n");
	scanf("%d",&num);
	NODE temp;
	temp = getNode();
	temp->value = num;
	temp->next = NULL;
	if(first==NULL){
		return temp;
	}
	temp->next = first;
	first = temp;
	return first;
}

NODE insertRear(NODE first){
	int num;
	printf("Enter the number\n");
	scanf("%d",&num);
	NODE curr,temp;
	temp = getNode();
	temp->value = num;
	temp->next = NULL;
	if(first == NULL){
		return temp;
	}
	curr = first;
	while(curr->next != NULL){
		curr=curr->next;
	}
	curr->next = temp;
	return first;
}

NODE insertPos(NODE first,int pos){
	int num;
	printf("Enter the number\n");
	scanf("%d",&num);
	NODE temp,curr,prev;
	int count=1;
	temp = getNode();
	temp->value = num;
	temp->next = NULL;
	if(pos==count){
		return temp;
	}
	curr = first;
	prev = NULL;
	while(curr!=NULL){
		if(count==pos){
			break;
		}
		prev=curr;
		curr=curr->next;
		count++;
	}
	if(curr==NULL){
		printf("Enterred position is more than length\n");
		return first;
	}
	temp->next = prev->next;
	prev->next = temp;
	return first;
}

void display(NODE first){
	NODE curr = first;
	while(curr!=NULL){
		printf("%d ",curr->value);
		curr = curr->next;
	}
	printf("\n");
}

NODE deleteFront(NODE first){
	NODE curr;
	if(first == NULL){
		printf("List is empty\n");
		return first;
	}
	if(first->next == NULL){
		printf("Deleted element = %d\n",first->value);
		freeNode(first);
		return NULL;
	}
	curr=first;
	curr=curr->next;
	printf("Deleted element = %d\n",first->value);
	freeNode(first);
	return curr;
}

NODE deleteRear(NODE first){
	NODE curr,prev=NULL;
	if(first == NULL){
		printf("List is empty\n");
		return first;
	}
	if(first->next == NULL){
		printf("Deleted element = %d\n",first->value);
		freeNode(first);
		return NULL;
	}
	curr = first;
	while(curr->next!=NULL){
		prev = curr;
		curr=curr->next;
	}
	prev->next = NULL;
	printf("Deleted element = %d\n",curr->value);
	freeNode(curr);
	return first;
}

NODE deletePos(NODE first,int pos){
	NODE curr,prev;
	if(first==NULL){
		printf("List is empty\n");
		return first;
	}
	int count=1;
	if(pos==count){
		printf("Deleted element = %d\n",first->value);
		curr = first;
		curr = curr->next;
		freeNode(first);
		return curr;
	}
	curr = first;
	prev = NULL;
	while(curr!=NULL){
		if(count==pos){
			break;
		}
		prev = curr;
		curr = curr->next;
		count++;
	}
	if(curr==NULL){
		printf("Enterred position is greater than length\n");
		return first;
	}
	prev->next = curr->next;
	printf("Deleted element = %d\n",curr->value);
	freeNode(curr);
	return first;
}

int main(){
	int ch;
	int pos;
	NODE first = NULL;
	while(1){
		printf("Enter the option\n1-insertFront\n2-insertRear\n3-insertPosition\n4-deletedFront\n5-deletedRear\n6-deletePosition\n7-display\n8-exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				first = insertFront(first);
				break;
			case 2:
				first = insertRear(first);
				break;
			case 3:
				printf("Enter the position for insertion\n");
				scanf("%d",&pos);
				first = insertPos(first,pos);
				break;
			case 4:
				first = deleteFront(first);
				break;
			case 5:
				first = deleteRear(first);
				break;
			case 6:
				printf("Enter the position for insertion\n");
				scanf("%d",&pos);
				first = deletePos(first,pos);
				break;
			case 7:
				display(first);
				break;
			case 8:
			return 0;
			break;	
		}
	}
}
