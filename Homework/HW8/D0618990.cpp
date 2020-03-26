#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

int size = 0, number[MAX+1] = {-1};

void Max_heap(int number[]) {
    int heap[MAX+1] = {-1};
    for(int i = 1; i <= MAX; i++) {
        heap[i] = number[i];
        int s = i;
        int p = i / 2;
        while(s >= 2 && heap[p] < heap[s]) {
            SWAP(heap[p], heap[s]);
            s = p;
            p = s / 2;
        }
    }
    printf("HEAP:\n");
    int level = 0;
    for(int i = 1, counter = 1, count = size; ; i++){
        count -= counter;
        if(count < 0) {
            level = i;
            break;
        }
        counter *= 2;
    }
    for(int i = 1, counter = 1, count = 1; i <= size; i++){
        for (int j = i; j < level; j++){
            printf("%2c",' ');
        }
    	number[i] = heap[i];
        printf("%2d ", number[i]);
        if(i == count){
            // counter *= 2;
            count += counter *= 2;
            printf("\n");
        }
	}
    printf("\n\n");
}

void del_Max_heap(int number[]){
    printf("Delete: %d\n", number[1]);
    for(int i = 1; i < size; i++){
    	number[i] = number[i+1];
	}
    --size;
    Max_heap(number);
}

int main(void) {
    FILE *inptr = NULL;

    inptr = fopen ("1.txt", "r");

    if (inptr == NULL) {
        printf ("failed to open file: File exists");
        fclose (inptr);
    } else {
        for(int i = 1; i <= MAX; i++){
        	if(fscanf(inptr, "%d", &number[i]) == EOF) break;
        	size = i;
        }
        fclose (inptr);
    }
    
    Max_heap(number);
    printf("ADD: ");
	scanf("%d",&number[++size]);
	Max_heap(number);
    del_Max_heap(number);
    return 0;
}