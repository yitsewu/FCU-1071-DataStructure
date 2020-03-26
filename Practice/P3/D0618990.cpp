#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	int number;
	struct node *next;
}NODE;

void push(NODE **dest) {
	NODE *current = *dest;
	NODE *new_node;
	
	int num;
	printf("push : \t\t");
	scanf("%d", &num);

	new_node = (NODE*)malloc(sizeof(NODE));
	new_node -> number = num;
	new_node -> next = NULL;
	
	while(1) {
		if(*dest == NULL) {
			*dest = new_node;
			break;
		} else {
			if(current -> next == NULL) {
				current -> next = new_node;
				break;
			} else {
				current = current->next;
			}
		}
	}
}

NODE* pop(NODE **dest) {
	NODE *current = *dest;
	NODE *del_node = NULL;
	
	if(current == NULL) {
		return NULL;
	} else if (current -> next == NULL){
		free(current);
		return NULL;
	} else {
		del_node = current;
		current = current -> next;
		free(del_node);
		return current;
	}
}

void peek(NODE *dest) {
	if(dest == NULL) {
		printf("NULL");
	} else {
		printf("%d\n", dest -> number);
	}
}

void size(NODE *dest) {
	NODE *current = dest;
	int size = 1;
	while(1){
		if(current == NULL) {
			printf("size : 0\n");
			break;
		} else if(current->next == NULL) {
			printf("size : %d\n", size);
			break;
		}
		size++;
		current = current->next;
	}
}

void printlist(NODE *print) {
	NODE *current = print;
	while(1){
		if(current == NULL) {
			printf("Empty!!!\n");
			break;
		} else if(current->next == NULL) {
			printf("%d\n", current->number);
			break;
		}
		printf("%d ", current->number);
		current = current->next;
	}
} 

int main() {
	int mode;
	NODE *head = NULL;

	while(1) {
		printf("1. push()\n2. pop()\n3. peek()\n4. size()\n0. exit()\n");
		printf("Please input your mode: ");
		scanf("%d", &mode);

		switch (mode) {
			case 0:
				free(head);
				return 0;
				break;
			case 1:
				printf("\nOriginal :\t");
				printlist(head);
				push(&head);
				printf("New :\t\t");
				printlist(head);
				break;
			case 2:
				printf("\nOriginal :\t");
				printlist(head);
				head = pop(&head);
				printf("New :\t\t");
				printlist(head);
				break;
			case 3:
				peek(head);
				break;
			case 4:
				size(head);
				break;
			default:
				break;
		}
		printf("\n");
	}
}
