#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode {
	int data;
	struct treeNode *leftChild;
	struct treeNode *rightChild;
} TreeNode;

typedef struct node {
	TreeNode *treeNode;
	struct node *next;
} NODE;

void treecreate(TreeNode **root, int num) {
	TreeNode *current = *root;
	TreeNode *new_node;
	
	new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node -> data = num;
	new_node -> leftChild = NULL;
	new_node -> rightChild = NULL;

	while(1) {
		if(*root == NULL) {
			*root = new_node;
			break;
		} else {
			if (new_node -> data < current ->data){
				if(current -> leftChild == NULL){
					current -> leftChild = new_node;
					break;
				} else {
					current = current -> leftChild;
				}
			} else {
				if(current -> rightChild == NULL){
					current -> rightChild = new_node;
					break;
				} else { 
					current = current -> rightChild;
				}
			}
		}
	}
}

TreeNode *pop(NODE **top_ref) {
	NODE *top = *top_ref;
	TreeNode *res = top -> treeNode;
	*top_ref = top -> next;
	free(top);
	return res;
}

void push(NODE **stack, TreeNode *treeNode) {
	NODE *new_treeNode = (NODE *)malloc(sizeof(NODE));
	new_treeNode -> treeNode = treeNode;
	new_treeNode -> next = (*stack);
	(*stack) = new_treeNode;
}

void Inorder(TreeNode *root) {
	TreeNode *current = root;
	NODE *stack = NULL;

	while (1) {
		if (current != NULL) {
			push(&stack, current);
			current = current->leftChild;
		} else {
			if (stack != NULL) {
				current = pop(&stack);
				printf("%d ", current -> data);
				current = current -> rightChild;
			} else {
				break;
			}
		}
	} 
}

int main (int argc, char const *argv[]) {
	TreeNode *root = NULL;
	FILE *inptr = NULL;
	int times, num;

    inptr = fopen ("C.txt", "r");

    if (inptr == NULL) {
        printf ("failed to open file: File exists");
        fclose (inptr);
    } else {
		fscanf(inptr,"%d", &times);
        for (int i = 0; i < times; i++) {
			fscanf(inptr,"%d", &num);
			treecreate(&root, num);
        }
        fclose (inptr);
    }
	
	Inorder(root);
	printf("\n");

	return 0;
}