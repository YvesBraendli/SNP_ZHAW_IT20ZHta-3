/**
 *  P02 Praktikum
 *
 *  Das Programm liest einen Monat (1-12) und ein Jahr (1600-2400) ein und
 *  gibt die Anzahl der Tage dieses Monats aus.
 *
 *  @author Gerrit Burkert, Adaptation bazz
 *  @version 15-FEB-2013, 16-OCT-2017, 17-OCT-2019, 16-FEB-2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ERROR_IN_MONTH 1
#define ERROR_IN_YEAR 2

int gibIntWert(char stringSwitch[], int min, int max);
int istSchaltjahr(int year);
int tageProMonat(int year, int month);


///// Student Code



///// END Student Code


int main (int argc, char *argv[]) {
    
    int monat, jahr;
     
    //  Monat einlesen und Bereich ueberpruefen
    monat = gibIntWert("Monat", 1, 12);
    jahr  = gibIntWert("Jahr", 1600, 9999);
	
    //  Ausgabe zum Test
    printf("Monat: %d, Jahr: %d \n", monat, jahr);    
    
    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

    // Ausgabe
    printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(4008, 2));
   
    return 0;
}

int gibIntWert(char stringSwitch[], int min, int max){
    if (stringSwitch[0]=='M'&&(min<1||max>12)){
        printf("Ungültiger Range für Monat. Geben sie einen Wert zwischen 1 und 12 ein.\n");
        exit(0);
    }
    if (stringSwitch[0]=='J'&&(min<=1599||max>=10000)){
        printf("Ungültiger Range für Jahr. Geben sie einen Wert zwischen 1600 und 9999 ein.\n");
        exit(0);
    }
    srand(time(0));
    int value = (rand() % (max - min + 1)) + min;
    return value;
}

int istSchaltjahr(int year){
    int checkSplitWithFour = year/4;
    int checkIsEvenHundreds = year/100;
    int checkSplitWithFourhundred = year/400;
    int isSwitchYear = 0;
    if (4*checkSplitWithFour == year&&(100*checkIsEvenHundreds!=year||400*checkSplitWithFourhundred==year)){
        isSwitchYear = 1;
    }
    return isSwitchYear;
}

int tageProMonat(int year, int month){
    int daysPerMonth;
    enum months { DAYNRHIGH=31, FEB=28, DAYNRLOW=30};
    switch (month){
        case 1: daysPerMonth=DAYNRHIGH;
            break;
        case 2: daysPerMonth=FEB;
            break;
        case 3: daysPerMonth=DAYNRHIGH;
            break;
        case 4: daysPerMonth=DAYNRLOW;
            break;
        case 5: daysPerMonth=DAYNRHIGH;
            break;
        case 6: daysPerMonth=DAYNRLOW;
            break;
        case 7: daysPerMonth=DAYNRHIGH;
            break;
        case 8: daysPerMonth=DAYNRHIGH;
            break;
        case 9: daysPerMonth=DAYNRLOW;
            break;
        case 10: daysPerMonth=DAYNRHIGH;
            break;
        case 11: daysPerMonth=DAYNRLOW;
            break;
        case 12: daysPerMonth=DAYNRHIGH;
            break;
    }
    if (istSchaltjahr(year)==1&&month==2){
        daysPerMonth++;
    }
    return daysPerMonth;
}
