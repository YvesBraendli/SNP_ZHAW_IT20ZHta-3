 /* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab P02 weekday
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// *** TASK1: typedef enum types for month_t (Jan=1,...Dec} ***
// BEGIN-STUDENTS-TO-ADD-CODE
enum month_t {JAN=1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
enum Wochentag {Sonntag=0, Montag, Dienstag, Mittwoch, Donnerstag, Freitag, Samstag};

// END-STUDENTS-TO-ADD-CODE



// *** TASK1: typedef struct for date_t ***
// BEGIN-STUDENTS-TO-ADD-CODE
struct date_t {
    int year;
    int month;
    int day;
};

// END-STUDENTS-TO-ADD-CODE

int is_leap_year(struct date_t date);
int get_month_length(struct date_t date);
int is_gregorian_date(struct date_t date);
void wochenTagAusgeben(struct date_t date);



// *** TASK2: typedef enum weekday_t (Sun=0, Mon, ...Sat) ***
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is a leap year.
 * @returns 0 = is not leap year, 1 = is leap year
 */
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Calculates the length of the month given by the data parameter
 * @returns 28, 29, 30, 31 if a valid month, else 0
 */
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is in the gregorian date range
 * @returns 0 = no, 1 = yes
 */
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Checks if the given date is a valid date.
 * @returns 0 = is not valid date, 1 = is valid date
 */
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK2: calculated from a valid date the weekday
 * @returns returns a weekday in the range Sun...Sat
 */
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE



/**
 * @brief   TASK2: print weekday as 3-letter abreviated English day name
 */
// BEGIN-STUDENTS-TO-ADD-CODE


// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   main function
 * @param   argc [in] number of entries in argv
 * @param   argv [in] program name plus command line arguments
 * @returns returns success if valid date is given, failure otherwise
 */
int main(int argc, const char *argv[])
{
    // TASK1: parse the mandatory argument into a date_t variable and check if the date is valid
    // BEGIN-STUDENTS-TO-ADD-CODE
    struct date_t givenDate;
    int res = sscanf(argv[1]
                , "%d-%d-%d"
                , &(givenDate.year), &(givenDate.month), &(givenDate.day)
                );
    if (res !=3||9999<givenDate.year||givenDate.year<1000||12<givenDate.month||givenDate.month<1||31<givenDate.day||givenDate.day<1){
        printf("Ungültige Eingabe, geben sie ein Datum in der Form yyyy-mm-dd ein.\n");
        exit(0);
    }
    if (is_gregorian_date(givenDate)){
        printf("Sie haben kein greogrianisches Datum eingegeben.\n");
        exit(0);
    }
    
    // END-STUDENTS-TO-ADD-CODE


    // TASK2: calculate the weekday and print it in this format: "%04d-%02d-%02d is a %s\n"
    // BEGIN-STUDENTS-TO-ADD-CODE
    wochenTagAusgeben(givenDate);

    // END-STUDENTS-TO-ADD-CODE

    return EXIT_SUCCESS;
}


int is_leap_year(struct date_t date)
{
    int checkSplitWithFour = date.year/4;
    int checkIsEvenHundreds = date.year/100;
    int checkSplitWithFourhundred = date.year/400;
    int isSwitchYear = 0;
    if (4*checkSplitWithFour == date.year&&(100*checkIsEvenHundreds!=date.year||400*checkSplitWithFourhundred==date.year)){
        isSwitchYear = 1;
    }
    return isSwitchYear;
}

int get_month_length(struct date_t date){
    int daysPerMonth;
    enum months { DAYNRHIGH=31, FEB=28, DAYNRLOW=30};
    switch (date.month){
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
    if (is_leap_year(date)==1&&date.month==2){
        daysPerMonth++;
    }
    return daysPerMonth;
}

int is_gregorian_date(struct date_t date)
{
    int isGregorian = 0;
    if (date.year>9999||date.year<1582
        ||(date.year==1582&&date.month<10)
            ||(date.year==1582&&date.month==10&&date.day<15)){
        isGregorian = 1;
    }
    return isGregorian;
}

void wochenTagAusgeben(struct date_t date) {
    int weekday, m, a, y, c;
    m = 1 + (date.month + 9) % 12;
    if(date.month == 1 || date.month == 2){
        a = date.year - 1;
    } else {
        a = date.year;
    }
    y = a % 100;
    c = a / 100;
    weekday = ((date.day + (13 * m - 1) / 5 + y + y / 4 + c / 4 - 2 * c) % 7 + 7) % 7;
    switch (weekday) {
        case (Montag):
            printf("Das eingegebene Datum ist ein Montag.\n");
            break;
        case (Dienstag):
            printf("Das eingegebene Datum ist ein Dienstag.\n");
            break;
        case (Mittwoch):
            printf("Das eingegebene Datum ist ein Mittwoch.\n");
            break;
        case (Donnerstag):
            printf("Das eingegebene Datum ist ein Donnerstag.\n");
            break;
        case (Freitag):
            printf("Das eingegebene Datum ist ein Freitag.\n");
            break;
        case (Samstag):
            printf("Das eingegebene Datum ist ein Samstag.\n");
            break;
        case (Sonntag):
            printf("Das eingegebene Datum ist ein Sonntag.\n");
            break;
        default:
            printf("Kein Wochentag für Input gefunden...\n");
    }
}

