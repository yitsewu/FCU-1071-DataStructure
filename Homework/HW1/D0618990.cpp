#include <stdio.h>
#define Max 100

typedef struct Array{
    int Size;                           
    int Arr[Max];
    void BubbleSort();                  
    void SelectionSort();               
    int BinarySearch(int Input);        //�G���j�M�k�A�q��L��J���M�䪺�ƭȡA���^�ǯ��ޭȡA�_�h�^��-1
    void ShowArr();                     //�L�X���c�Ҧ�����
}Array;

void swap(int *a, int *b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}

void Array::BubbleSort(){
	for(int i = 0; i < Size; i++){
		for(int j = 0; j < (Size-i-1); j++){
			if(Arr[j] > Arr[j+1]){
				swap(&Arr[j],&Arr[j+1]);
			}
		}
	}
}

void Array::SelectionSort(){
	for(int i = 0; i < Size; i++){
		for(int j = i; j < Size; j++){
			if(Arr[j] < Arr[i]){
				swap(&Arr[j],&Arr[j+1]);
			}
		}
	}
}

int Array::BinarySearch(int Input){
	int low = 0, up = Size - 1, middle;

    while(low <= up){
        middle = (low + up) / 2;
    	if(Arr[middle] == Input){
			printf("%d is Exists\n", Arr[middle]);
			return middle;
		} else if(Arr[middle] > Input) {
			up = middle - 1;
		} else {
			low  = middle + 1;
		}
    }
    
    printf("Not Exists\n");
    return -1;
}

void Array::ShowArr(){
	for(int i = 0; i < Size; i++){
		printf("%2d ", Arr[i]);
	}
	printf("\n\n");
}

int main(){
    FILE *inptr = fopen("A1.txt", "r");
    
	int search;
    Array Data;
	
	for(Data.Size = 0; ; Data.Size++){
		if(fscanf(inptr, "%d", &Data.Arr[Data.Size]) == EOF) break;
	}
		
	printf("Original:\n");
	Data.ShowArr();
	
	printf("BubbleSort:\n");
	Data.BubbleSort();
	Data.ShowArr();
	
	printf("SelectionSort:\n");
	Data.SelectionSort();
	Data.ShowArr();
	
	printf("Input the number which you want to search: ");
    scanf("%d", &search);
    Data.BinarySearch(search);
	
	fclose(inptr);
	
    return 0;
}

