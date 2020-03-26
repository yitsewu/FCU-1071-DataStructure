#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct polynomial {
    float coef;
    int expon;
}polynomial;

typedef struct mypoly {
    polynomial terms[MAX];
    int size;
    void showPoly ();
    void add (mypoly);
    void singleMult (int);
    float leadExp ();
    void attach (float, int);
    void del (int);
}Mypoly;

void Mypoly::showPoly(){
    for (int i = 0; i < size; i++) {
        if (i == size-1) {
            printf("%.0fx^%d\n",terms[i].coef, terms[i].expon);
        } else {
            printf("%.0fx^%d + ",terms[i].coef, terms[i].expon);
        }
    }
}

void Mypoly::add (mypoly poly) {
    for (int i = 0; i <= poly.size; i++) {
        terms[i+size] = poly.terms[i];
    }
    
    size += poly.size;
    
    
	for(int i = 0; i < size; i++) {
		for(int j = i; j < size; j++) {
			if(terms[j].expon > terms[i].expon){
				polynomial temp = terms[j];
				terms[j] = terms[i];
				terms[i] = temp;
			}
		}
	}
	
	for(int i = 0; i < size; i++){
		if(terms[i].expon == terms[i+1].expon && i < size-1) {
			terms[i].coef += terms[i+1].coef;
			for(int j = i + 1; j < size; j++) {
				if(j < size){
					terms[j] = terms[j+1];
				}
			}
			size -= 1;
		}
	}
	showPoly();
}

void Mypoly::singleMult (int num) {

    for (int i = 0; i < size; i++) {
        terms[i].coef *= num;
    }
    
    showPoly();
}

float Mypoly::leadExp() {
    return terms[0].coef;
}

void Mypoly::attach (float coef, int expon) {
    mypoly input;
    input.size = 1;
    input.terms[0].coef = coef;
    input.terms[0].expon = expon;
    add(input);
}

void Mypoly::del(int expon) {
	
    for(int i = 0; i < size; i++) {
		if(terms[i].expon == expon && i < (size-1)) {
			for(int j = i; j < size; j++) {
				if(j < size) {
					terms[j] = terms[j+1];
				}
			}
			size -= 1;
		}
	}
	showPoly();
}

int Data_loading (Mypoly *poly, int num) {
	
    char filename[] = "poly";
    char filetype[] = ".txt";
    char fullname[10];
    sprintf(fullname,"%s%c%s",filename, num+'0', filetype);
	
    FILE *inptr = fopen(fullname, "r");
    
    if (inptr == NULL) {
    	printf("failed to open file: poly%d.txt",num);
    	fclose(inptr);
    	return -1;
	} else {
		for (poly->size = 0; ; poly->size++) {
            if (fscanf(inptr, "%f%d", &poly->terms[poly->size].coef, &poly->terms[poly->size].expon) == EOF) break;
        }
        fclose(inptr);
        return 1;
	}
    
}


int main(void){
    Mypoly poly1, poly2;
	int end = 0, a;
    int flag = 0;

    while(1){
        printf ("\n------ 多項式 ADT ------\n\n");
        printf ("1. 讀⼊多項式\n2. 印出多項式內容\n3. 多項式相加\n4. 多項式乘上⼀數值\n5. 印出多項式中最⼤指數的係數\n6. 新增項式\n7. 刪除多項式中的項式\n0. exit\n\nMODE: ");
        scanf ("%d",&a);
        
        if (a == 1 || a == 0) flag = 1;
        if (flag != 1) {
            printf("Please Loading Data first\n");
            continue;
        }
        switch (a) {
            case 0 :
                end = 1;
                break;
            case 1 :
                (Data_loading(&poly1, 1) == 1 && Data_loading(&poly2, 2) == 1)? printf("Data loading Success!!!\n") : end = 1;
                break;
            case 2 :
                printf("poly1 : ");
                poly1.showPoly();
                printf("poly2 : ");
                poly2.showPoly();
                break;
            case 3 :
                poly1.add(poly2);
                break;
            case 4 :
                poly1.singleMult(3);
                break;
            case 5 :
                printf("%.f",poly1.leadExp());
                break;
            case 6 :
                poly1.attach(9, 24);
                break;
            case 7 :
                poly1.del(5);
                break;
            default:
            	printf("Input Error!!!\n");
                break;
        }
        printf("\n");
        if(end) return 0;
    }
}