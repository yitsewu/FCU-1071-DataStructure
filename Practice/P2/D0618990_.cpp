#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct grade {
    int chinese;        //中文分數
    int math;           //數學分數
    int english;        //英文分數
} grade;

typedef struct info {
    int stuid;          //學號
    char name[10];      //姓名
    struct grade gra;   //成績結構
} info;

typedef struct classes {
    struct info terms[MAX];                     //班級資料
    int size;                                   //班級人數
    void AddStuInfor(int, char , int, int, int); //新增一筆學生資料
    int IndexOfStu(int);                        //尋找學號在陣列的索引值，若無回傳-1
    void Show();                                //印出全班級資料含成績
    void ShowStuInfo(int);                      //印出某一位學生資料含成績
    void Average();                             //印出各科平均分數
    void StuAverage(int);                       //印出某一位學生的各科平均分數
} classes;

void classes::Show(){
    printf ("\nStudent : %d \n\n", size);
    printf ("No.  ID   \tName\tChinese\tmath\tEnglish\n");
    for (int i = 0; i < size ; i++) {
        printf ("%2d. %8d\t%s\t%d\t%d\t%d\n", i+1, terms[i].stuid, terms[i].name, terms[i].gra.chinese, terms[i].gra.math, terms[i].gra.english);
    }
}

void classes::ShowStuInfo(int ST_ID) {
    for (int i = 0; i < size ; i++) {
        if (terms[i].stuid == ST_ID) {
            printf ("\nID   \tName\tChinese\tmath\tEnglish\n");
            printf ("%7d\t%s\t%d\t%d\t%d\n", terms[i].stuid, terms[i].name, terms[i].gra.chinese, terms[i].gra.math, terms[i].gra.english);
            return;
        }
    }
    printf ("Not found\n");
}

int Loading_data(classes *class_a){
    FILE *inptr = NULL;
    inptr = fopen ("C.txt", "r");

    if (inptr == NULL) {
        printf ("failed to open file: File exists");
        fclose (inptr);
        return -1;
    } else {
        for (class_a ->size = 0; ; class_a->size ++) {
            if ((fscanf(inptr,"%d%s%d%d%d", &class_a->terms[class_a->size].stuid, class_a->terms[class_a->size].name, &class_a->terms[class_a->size].gra.chinese, &class_a->terms[class_a->size].gra.math, &class_a->terms[class_a->size].gra.english)) == EOF) break;
        }
        fclose (inptr);
        return 1;
    }
    
}

void write_data (classes *class_a) {
    FILE *outptr = NULL;
    outptr = fopen ("C.txt", "w");
    for (int i = 0; i < class_a->size; i++) {
        fprintf(outptr,"%d %s %d %d %d\n", class_a->terms[i].stuid, class_a->terms[i].name, class_a->terms[i].gra.chinese, class_a->terms[i].gra.math, class_a->terms[i].gra.english);
    }
    fclose(outptr);
}

int main (int argc, char const *argv[]) {
    classes class_a;
    int a;
    
    while(Loading_data(&class_a)){
        printf ("\n------ Welecome ------\n\n");
        printf ("1. 印出全班資料\n2. 印出學生資料\n\n0. exit\n\nMODE: ");
        scanf ("%d",&a);
        
        switch (a) {
            case 0 :
                return 0;
            case 1 :
                class_a.Show();
                break;
            case 2 :
                int ST_ID;
                printf("Student ID : ");
                scanf("%d", &ST_ID);
                class_a.ShowStuInfo(ST_ID);
                break;
            default:
                printf("error\n");
        }
        write_data(&class_a);
        printf("\n");
    }
}