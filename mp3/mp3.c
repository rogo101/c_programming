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
