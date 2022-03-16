/*
main
*/
#include <stdlib.h>
#include <stdio.h>

void basicOperations();
void changingVariables();
void lowerUpperCase();
void powerOf2();




int main() {
  printf("Basic Operations: \n");
  basicOperations();
  printf("\n");
  printf("Changing Variables: \n");
  changingVariables();
  printf("\n");
  printf("Lower-/Uppercase: \n");
  lowerUpperCase();
  printf("\n");
  printf("Power of 2: \n");
  powerOf2(); 
  return EXIT_SUCCESS;
}


/*
Exercise 1: Basic Operations
*/



void basicOperations() {
  unsigned int number = 0x75;
  unsigned int bit = 3; // bit at position 3

  // Setting a bit
  number |= (1 << bit);
  
  // Clearing a bit
  bit = 1;
  number &= ~(1<<bit);
  
  // Toggling a bit
  bit = 0;
  number ^=(1<<bit);

  printf("number = 0x%02X\n", number);
}


/*
Exercise 2: Changing Variables
*/

void changingVariables(){
  int a = 3;
  int b = 4;
  printf("a: %d; b: %d\n", a, b);
  
  a ^= b;
  b ^= a;
  a ^= b;
  
  printf("a: %d; b: %d\n", a, b);
}

/*
Exercise 3: Lower-/ Uppercase
*/

void lowerUpperCase(){
  char word[8] = "sREedEv";
  char *wordptr = &word[0];

  while(wordptr < &word[7]) {
    printf("UPPERCASE: %c\n", *wordptr & '_'); // converts the char into uppercase regardless of the current casing
    printf("LOWERCASE: %c\n", *wordptr | ' '); // converts the char into lowercase regardless of the current casing
    wordptr++;
    /*
    Weil es die "Mittelwerte" sind
    */
  }
}

/*
Exercise 4: Power of 2
*/

void powerOf2(){
  int a = 10; // any positive number
  int b = a-1;
  if(a > 0 
     && ((a&b)==0)){
    printf("%d is a power of 2\n", a);
  }
}
