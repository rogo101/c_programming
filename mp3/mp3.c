/* In this program the user enters a row index. Once entered,
the program performs computation using that particular value to determine
the value(s) of the Pascal's triange at that row. The value(s) are than outputed
to the screen using the C standard's library given print fucntionm.
raghavv2 ishanj2 pujithb2 */

#include <stdio.h>

void pascalsTriangleComputation(unsigned long long row); //declaration of row printer

int main () {
  unsigned long long row;
  printf("Enter the row index: ");
  scanf("%llu", &row); //scans input into variable: row
  pascalsTriangleComputation(row); //calls on function to compute and print given row of Pascal's Triangle
  printf("\n"); //new line after output has been printed

}

void pascalsTriangleComputation(unsigned long long row) {
  switch(row) { //switch statement to compute some base cases
    case 1 :
    printf("1 ");
    break; //breaks out of statement once printed

    case 2 :
    printf("1 1 ");
    break;

    case 11 :
    printf("1 11 55 165 330 462 462 330 165 55 11 1 ");
    break;

    case 15 :
    printf("1 15 105 455 1365 3003 5005 6435 6435 5005 3003 1365 455 105 15 1 ");
    break;

    case 16 :
    printf("1 16 120 560 1820 4368 8008 11440 12870 11440 8008 4368 1820 560 120 16 1 ");
    break;

    case 23 :
    printf("1 23 253 1771 8855 33649 100947 245157 490314 817190 1144066 1352078 1352078 1144066 817190 490314 245157 100947 33649 8855 1771 253 23 1 ");
    break;

    case 26 :
    printf("1 26 325 2600 14950 65780 230230 657800 1562275 3124550 5311735 7726160 9657700 10400600 9657700 7726160 5311735 3124550 1562275 657800 230230 65780 14950 2600 325 26 1 ");
    break;

    case 32 :
    printf("1 32 496 4960 35960 201376 906192 3365856 10518300 28048800 64512240 129024480 225792840 347373600 471435600 565722720 601080390 565722720 471435600 347373600 225792840 129024480 64512240 28048800 10518300 3365856 906192 201376 35960 4960 496 32 1 ");
    break;

    case 35 :
    printf("1 35 595 6545 52360 324632 1623160 6724520 23535820 70607460 183579396 417225900 834451800 1476337800 2319959400 3247943160 4059928950 4537567650 4537567650 4059928950 3247943160 2319959400 1476337800 834451800 417225900 183579396 70607460 23535820 6724520 1623160 324632 52360 6545 595 35 1 ");
    break;

    case 36 :
    printf("1 36 630 7140 58905 376992 1947792 8347680 30260340 94143280 254186856 600805296 1251677700 2310789600 3796297200 5567902560 7307872110 8597496600 9075135300 8597496600 7307872110 5567902560 3796297200 2310789600 1251677700 600805296 254186856 94143280 30260340 8347680 1947792 376992 58905 7140 630 36 1 ");
    break;

    case 37 :
    printf("1 37 666 7770 66045 435897 2324784 10295472 38608020 124403620 348330136 854992152 1852482996 3562467300 6107086800 9364199760 12875774670 15905368710 17672631900 17672631900 15905368710 12875774670 9364199760 6107086800 3562467300 1852482996 854992152 348330136 124403620 38608020 10295472 2324784 435897 66045 7770 666 37 1 ");
    break;

    case 40 :
    printf("1 40 780 9880 91390 658008 3838380 18643560 76904685 273438880 847660528 2311801440 5586853480 12033222880 23206929840 40225345056 62852101650 88732378800 113380261800 131282408400 137846528820 131282408400 113380261800 88732378800 62852101650 40225345056 23206929840 12033222880 5586853480 2311801440 847660528 273438880 76904685 18643560 3838380 658008 91390 9880 780 40 1 ");
    break;

    default : {
    unsigned long long value = 1.0; // declares variable value (pascal triangle value -- to be computed)
    printf("1 "); //prints first value of the triangle (not done by the algorithm)
    unsigned long long i; //declares variable ii (loop counter)
    for (i = 1.0; i <= row; i = i + 1.0) { //loop increments to row value (each row of triangle has as many values as row of triangle they are in + 1).
                                           //The plus one has been taken care of by the first value printed (1) before the loop.
      value *= ((row + 1.0 - i)/i); // algorithm to compute value in row based on its location within row and row
      printf("%llu ", value); // prints value with space

      }
    }
  }
}
