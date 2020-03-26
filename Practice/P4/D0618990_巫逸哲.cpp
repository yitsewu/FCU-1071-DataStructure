#include <stdio.h>
#include <string.h>
#define MAX 100


typedef struct MyString{
    char str[MAX];
    int length();
    int find(char*);
    void insert(int, char*);
    void replace(char*, char*);
    void remove(char*);
    void reverse();
} MyString;

int Menu(){
    printf("1. 輸入字串\n2. 印出字串\n3. 印出字串長度\n4. 插入字串\n5. 取代字串\n6. 刪除字串\n7. 字串反轉\n0. Exit\n> ");
    return 1;
}

int MyString::length() {
    return strlen(str);
}

int MyString::find(char *str2) {
    if(strstr(str,str2) == NULL) {
        return -1;
    } else {
        return strstr(str,str2) - str;
    }
}

void MyString::insert(int index, char *str2) {
    int top = length() + strlen(str2);
    for (int i = top; i >= index; i--) {
        str[i + strlen(str2)] = str[i];
    }
    for (int i = 0; i < strlen(str2); i++) {
        str[index + i] = str2[i];
    }
}

void MyString::replace(char *str1, char *str2) {
    if (find(str1) != -1) {
        insert(find(str1),str2);
        remove(str1);
    }
}

void MyString::remove(char *str2) {
    if (find(str2) != -1) {
        for (int i = find(str2); ; i++) {
            if(i == length() - strlen(str2)) {
                str[i] = '\0';
                break;
            } else {
                str[i] = str[i + strlen(str2)];
            }
        }
    }
}

void MyString::reverse() {
    for (int i = 0; i < (length()/2); i++) {
        char temp = str[i];
        str[i] = str[(length()-i-1)];
        str[(length()-i-1)] = temp;
    }
}

int main(int argc, char const *argv[]) {
    MyString myStr;
    int input_flag = 0;
    
    while(Menu()) {
        int mode, index;
        char bechange[MAX], change[MAX];

        if(scanf("%d", &mode) == 1) {
            while(getchar() != '\n');       //fflush(stdin) not working in linux
        } else {
            while(getchar() != '\n');       //fflush(stdin) not working in linux
            mode = -1;
        }
        
        switch (mode) {
            case 1 :
                scanf("%[^\n]s",myStr.str); 
                /* 
                if using gets() maybe lead to buffer overflows, and also fgets() will put '\n' in to the str array.
                So using RE to solve the problem if the user input the str with ' ';
                */
                break;
            case 2 :
                puts(myStr.str);
                break;
            case 3 :
                printf("%d\n",myStr.length());
                break;
            case 4 :
                printf("輸入欲插入位置(index): ");
                scanf("%d",&index);
                printf("輸入欲插入內容: ");
                scanf("%s", change);
                myStr.insert(index, change);
//              myStr.insert(6, "xyz");
                break;
            case 5 :
                printf("將: ");
                scanf("%s", bechange);
                printf("取代為: ");
                scanf("%s", change);
                myStr.replace(bechange, change);
//              myStr.replace("forma", "tui");
                break;
            case 6 :
                printf("刪除文字: ");
                scanf("%s", change);
                myStr.remove(change);
//              myStr.remove("at");
                break;
            case 7 :
                myStr.reverse();
                break;
            case 0 :
                return 0;
                break;
            default:
                printf("Input Error!!!\n");
                break;
        }
        putchar('\n');
    }
}
