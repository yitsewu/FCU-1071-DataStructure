#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    int data;
    struct ListNode *llink;
    struct ListNode *rlink;
} ListNode;

typedef struct DoublyLinkedList{
    ListNode *first = NULL;
    ListNode *last = NULL;
    void queue(int data);
    void insertLeft(int data, int position);
    void remove(int position);
    int search(int data);
    void print();
} DoublyLinkedList;

ListNode* newnode(int data) {
    ListNode *new_node;
    new_node = (ListNode*) malloc(sizeof(ListNode));
	new_node -> data = data;
	new_node -> llink = NULL;
    new_node -> rlink = NULL;
    return new_node;
}

void DoublyLinkedList::queue(int data) {
    ListNode *current = first;
    ListNode *new_node = newnode(data);
    while(1) {
        if (first == NULL) {
            first = new_node;
            break;
        } else {
            if(current -> rlink == NULL) {
				current -> rlink = new_node;
                current -> rlink -> llink = current;
                last = current;
				break;
			} else {
				current = current -> rlink;
			}
        }
    }
}

void DoublyLinkedList::insertLeft(int data, int position) {
    ListNode *current = first;
    ListNode *new_node = newnode(data);
    for (int i = 0; i<= position; i++){
		if(current == NULL) break;
        if(i == position) {
            new_node -> llink = current -> llink;
            new_node -> rlink = current;
            current -> llink -> rlink = new_node;
            current -> llink = new_node;
            break;
        } else {
            current = current->rlink;
        }
	}
}

void DoublyLinkedList::remove(int position) {
    ListNode *current = first;
    for (int i = 0; i<= position; i++){
		if(current == NULL) break;
        if(i == position) {
            current -> llink -> rlink = current -> rlink;
            current -> rlink -> llink = current -> llink;
            free(current);
            break;
        } else {
            current = current->rlink;
        }
	}
}

int DoublyLinkedList::search(int data) {
    ListNode *current = first;
    for (int i = 0; ; i++){
        if(current == NULL) return -1;
		if(current -> data == data) {
            return i;
		} else {
            current = current -> rlink;
		}
	}
}

void DoublyLinkedList::print(){
    ListNode *current = first;
	while(1){
		if(current == NULL) {
			printf("Empty!!!\n");
			break;
		} else if(current -> rlink == NULL) {
			printf("| %d |\n", current -> data);
			break;
		}
		printf("| %d | -> ", current->data);
		current = current->rlink;
	}
}

int Data_loading (DoublyLinkedList *list) {
	FILE *inptr = fopen("test.txt", "r");
    int input, index;
    char mode;
    if (inptr == NULL) {
    	fclose(inptr);
    	return -1;
	} else {
		while(fscanf(inptr, "%c", &mode) != EOF) {
            switch (mode) {
                case 'q':
                    fscanf(inptr, "%d", &input);
                    list -> queue(input);
                    break;
                case 'i':
                    fscanf(inptr,"%d%d", &input, &index);
                    list -> insertLeft(input, index);
                    break;
                case 'r':
                    fscanf(inptr, "%d", &index);
                    list -> remove(index);
                    break;
                case 's':
                    fscanf(inptr, "%d", &input);
                    printf("search(%d): return %d\n", input, list -> search(input));
                    break;
                case 'p':
                    list -> print();
                    break;
                default:
                    return 1;
                    break;
            }
            getc(inptr);
        }
        fclose(inptr);
        return 0;
	}
}

int main(int argc, char const *argv[]) {
    DoublyLinkedList list;

    switch (Data_loading(&list)){
        case 1:
            printf("Error in test.txt input.\n");
            break;
        case -1:
            printf("Failed to open file: test.txt.\n");
            break;
    }
    return 0;
}