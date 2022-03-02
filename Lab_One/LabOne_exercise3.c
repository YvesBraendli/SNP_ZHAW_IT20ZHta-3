/* Counting */
#include <stdio.h>
#include <stdlib.h>
void count(void);


int main(void)
{
    count();
    return EXIT_SUCCESS;
}


void count(void)
{
   int numberOfSigns = 0;
    int numberOfWords = 0;
    char actualCaracter;
    while (actualCaracter != '\n')
    {
        actualCaracter = getchar();
        if (actualCaracter == ' '|| actualCaracter == '\t')
        {
            numberOfWords++;
        }
        else
        {
            numberOfSigns++;
        }
    }
    numberOfWords++;
    numberOfSigns--;
    (void) printf("The number of Signs is: %d\n", numberOfSigns);
    (void) printf("The number of Words is: %d\n", numberOfWords); 
}