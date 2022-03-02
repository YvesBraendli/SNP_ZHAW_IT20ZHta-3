/* Bitcoin */
#include <stdio.h>
#include <stdlib.h>
#define NUM_ROWS 8
void printLines(double factor);
double userInput(void);


int main(void)
{
    printLines(userInput());
    return EXIT_SUCCESS;
}

double userInput(void)
{
    (void) printf("Enter conversion rate (BTC --> CHF): ");
    double factor;
    scanf("%lf", &factor);
    return factor;
}

void printLines(double factorToCalculate)
{
   int valueCHF = 0;
   for(int i = 0; i <= NUM_ROWS; i++)
   {
       valueCHF += 200;
       double valueBTC = (1/factorToCalculate)*valueCHF;
        if (valueCHF < 1000)
        {
            (void) printf(" ");
        }
        (void) printf("%d", valueCHF);
        (void) printf("CHF          <--->           %lf", valueBTC);
        (void) printf(" BTC\n");
   }
   return;    
}