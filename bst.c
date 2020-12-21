#include<stdio.h>
#include<malloc.h>

struct node{
	struct node *left;
	int value;
	struct node *right;
};

typedef struct node *NODE;

NODE getNode(){
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	return temp;
}

NODE insert(NODE root){
	int value;
	NODE temp,curr,prev;
	temp = getNode();
	printf("Enter the value\n");
	scanf("%d",&value);
	temp->value = value;
	temp->left = NULL;
	temp->right = NULL;
	if(root==NULL){
		return temp;
	}
	curr = root;
	prev = NULL;
	while(curr!=NULL){
		prev = curr;
		if(value<curr->value){
			curr = curr->left;
		}else{
			curr = curr->right;
		}
	}
	if(value<prev->value){
		prev->left = temp;
	}else{
		prev->right = temp;
	}
	return root;
}

void display(NODE root,int i){
	int j;
	if(root!=NULL){
		display(root->right,i+1);
		for(j=0;j<i;j++){
			printf(" ");
		}
		printf("%d\n",root->value);
		display(root->left,i+1);
	}
}

void preOrder(NODE root){
	if(root==NULL){
		return;
	}
	printf("%d ",root->value);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(NODE root){
	if(root == NULL){
		return;
	}
	inOrder(root->left);
	printf("%d ",root->value);
	inOrder(root->right);
}

void postOrder(NODE root){
	if(root == NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->value);
}

int main(){
	int chq;NODE root = NULL;
	while(1){
		printf("Enter the choice\n1-insert\n2-display\n3-preOrder\n4-inOrder\n5-postOrder\n6-exit\n");
		scanf("%d",&chq);
		switch(chq){
			case 1:
				root = insert(root);
				break;
			case 2:
				if(root==NULL){
					printf("Tree is empty\n");
				}else{
					display(root,0);
				}
				break;
			case 3:
				if(root==NULL){
					printf("Tree is empty\n");
				}else{
					preOrder(root);
					printf("\n");
				}
				break;
			case 4:
				if(root==NULL){
					printf("Tree is empty\n");
				}else{
					inOrder(root);
					printf("\n");
				}
				break;
			case 5:
				if(root==NULL){
					printf("Tree is empty\n");
				}else{
					postOrder(root);
					printf("\n");
				}
				break;
			case 6:
				return 0;
		}
	}
}
