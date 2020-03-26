#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *inptr = NULL, *outptr = NULL;
	inptr = fopen(argv[1], "r");
	if (inptr != NULL) {
        printf("failed to open file: File exists");
        fclose(inptr);
        return 0;
    } else {
        outptr = fopen(argv[1], "w");
        printf("writing \"");
        for (int i = 0; ;i++) {
            if(argv[1][i] != '.')
                printf("%c",argv[1][i]);
            else
                printf("\"");
                break;
        }

        printf(" (uuse ctrl + d to send EOF)\n");
        printf("--------------------------------------------------------------------------------");
        
        while (1) {
            char input = getchar();
            if (input == EOF) {
                break;
            } else {
                fprintf(inptr, "%c", input);
            }
        }
        fclose(outptr);
    }
	return 0;
}