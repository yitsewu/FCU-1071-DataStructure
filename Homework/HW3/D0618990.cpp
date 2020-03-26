#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 64

int parent(int index) {
    return index / 2;
}

int left(int index) {
    return index * 2;
}

int right(int index) {
    return index * 2 + 1;
}

void Binary_tree(int i,char input[MAX], char tree[MAX+1]) {
    int index = 1;
    while(1) {
        if (input[i] < tree[index]) {
            if (tree[left(index)] == 0) {
                tree[left(index)] = input[i];
                break;
            } else {
                index =left(index);
            }
        } else if (input[i] > tree[index]) {
            if (tree[right(index)] == 0) {
                tree[right(index)] = input[i];
                break;
            } else {
                index =right(index);
            }
        }
    }
}

void level_order_pf(char tree[MAX+1], int size) {
    int counter = 1, enter_fg = 1, check = 0;
    for(int i = 1; i < MAX; i++) {
        
        if (tree[i] == 0) {
            printf("□");
        } else {
            printf("%c",tree[i]);
            check = 0;
        }
        if (i == enter_fg) {
            counter = counter*2;
            enter_fg = enter_fg + counter;
            printf("\n");
            check = 1;
        }
        if (i >= size-1 && check == 1) break;
    }
}

void inorder_pf(char tree[MAX+1], int index) {
    if (tree[index] != 0) {
        inorder_pf(tree,left(index));
        printf("%c ", tree[index]);
        inorder_pf(tree,right(index));
    }
}

int main(int argc, char const *argv[]) {
    int size = 1;
    char input[MAX], tree[MAX+1];
    memset(tree, 0, sizeof(tree));
    scanf("%s", input);

    for(int i = 0; i < MAX; i++) {
        if (input[i] == '\0') {
            break;
        } else if (i == 0) {
            tree[i+1] = input[i];
        } else {
            Binary_tree(i, input, tree);
        }
    }

    for (int i = 1; i < MAX+1; i++) {
        if(tree[i] != 0) {
            size = i + 1;
        }
    } 

    printf("level order: \n");
    level_order_pf(tree,size);

    printf("\n\n");

    printf("Inorder: \n");    
    inorder_pf(tree, 1);
    printf("\n");

    return 0;
}