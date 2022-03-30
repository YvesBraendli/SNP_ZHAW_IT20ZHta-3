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
    while (wordCount<10
    &&strcmp(words[wordCount],"ZZZ")!=0){
        wordCount+=1;
        scanf("%s", words[wordCount]);
        if (strlen(words[wordCount])>20){
            printf("Wort zu lang, es sind nur maximal 20 Zeichen erlaubt.\n");
            exit(0);
        }
    }
    printf("Inserted: %s", words[1]);
    return EXIT_SUCCESS;
}
