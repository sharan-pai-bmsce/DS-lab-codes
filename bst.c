#include<stdio.h>
#include<malloc.h>

struct node{
	int value;
	struct node *left;
	struct node *right;
};

typedef struct node *NODE;

NODE getNode(){
	NODE temp = (NODE)malloc(sizeof(struct node));
	return temp;
}

void freeNode(NODE temp){
	free(temp);
}

NODE insert(NODE root){
	NODE temp = getNode();
	printf("Enter the number\n");
	scanf("%d",&temp->value);
	temp->left = NULL;
	temp->right = NULL;
	if(root==NULL){
		return temp;
	}
	NODE prev = NULL;
	NODE curr = root;
	while(curr!=NULL){
		prev = curr;
		if(temp->value<curr->value){
			curr = curr->left;
		}else{
			curr = curr->right;
		}
	}
	if(temp->value<prev->value){
		prev->left = temp;
	}else{
		prev->right = temp;
	}
	return root;
}

void display(NODE root,int i){
	int j;
	if(root!=NULL){
		display(root->right,i+2);
		for(j=0;j<i;j++){
			printf(" ");
		}
		printf("%d\n",root->value);
		display(root->left,i+2);
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
	if(root==NULL){
		return;
	}
	inOrder(root->left);
	printf("%d ",root->value);
	inOrder(root->right);
}

void postOrder(NODE root){
	if(root==NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->value);
}

NODE deleteEle(NODE root){
	if(root==NULL){
		printf("Tree is empty\n");
		return  root;
	}
	int value;
	printf("Enter the value to be deleted\n");
	scanf("%d",&value);
	NODE curr = root;
	NODE q = NULL;
	NODE succ = NULL;
	NODE parent = NULL;
	while(curr!=NULL&&value!=curr->value){
		parent = curr;
		if(value<curr->value){
			curr = curr->left;
		}else{
			curr = curr->right;
		}
	}
	if(curr==NULL){
		printf("Tree is empty\n");
		return root;
	}	
	if(curr->left==NULL){
		q = curr->right;
	}else if(curr->right==NULL){
		q = curr->left;
	}else{
		succ = curr->right;
		while(succ->left!=NULL){
			succ = succ->left;
		}
		succ->left = curr->left;
		q = curr->right;
	}
	
	if(parent==NULL){
		printf("Deleted=%d\n",curr->value);
		freeNode(curr);
		return q;
	}else if(parent->left==curr){
		parent->left = q;
	}else{
		parent->right = q;
	}
	printf("Deleted = %d\n",curr->value);
	freeNode(curr);
	return root;
}

int main(){
	int chq;NODE root = NULL;
	while(1){
		printf("Enter the choice\n1-insert\n7-delete\n2-display\n3-preOrder\n4-inOrder\n5-postOrder\n6-exit\n");
		scanf("%d",&chq);
		switch(chq){
			case 1:
				root = insert(root);
				break;
			case 7:
				root = deleteEle(root);
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
