/*
String_Sort

Takes up to 10 words from the console with a maximum of 20 char and saves them in a two-dimensional Array

Afterwards the words are sorted alphabeticaly and printed on the console
To compare the Strings, the library (include <string.h>) should be used

The input should terminate, either when ZZZ is typed as word or the 10 words max is reached
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main (void){
    char words[10][20];
    int wordCount=0;
    int flag = 0;
    while (wordCount<10
    &&flag==0){
        scanf("%s", words[wordCount]);
        if (strcmp(words[wordCount],"ZZZ")==0){
            flag=1;
        }
        if (strlen(words[wordCount])>20){
            printf("Wort zu lang, es sind nur maximal 20 Zeichen erlaubt.\n");
            exit(0);
        }
        wordCount+=1;
    }
    for (int k=0; k<10; k++){
        int min = k;
        for (int i=k+1; i<10; i++){
            if (strcmp(words[i],words[min])<0){
                min=i;
            }
        }
        if (strcmp(words[min],words[k])!=0){
            char temp;
            temp = *words[min];
            *words[min] = *words[k];
            *words[k] = temp;
        }
    }
    printf("Sorted List:\n");
    for (int z=0; z<10;z++){
        printf("%s\n", words[z]);
    }
    return EXIT_SUCCESS;
}
