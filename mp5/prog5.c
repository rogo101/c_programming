/* In this program, we developed a game using random functions.
We used these functions to generate four random values, with which we prompted
the user to guess them within 6 tries. Each time one of the numbers matched perfectly (value and order),
the user was told. If it matched unorderdly the user was told as well. Once the user guessed
the values correctly the program ended and they were told the number of guesses they took.
If they did not guess within six tries the user failed.
raghavv2 pujithb2 ishanj2*/



/*
 * The functions that you must write are defined in the header file.
 * Blank function prototypes with explanatory headers are provided
 * in this file to help you get started.
 */



#include <stdio.h>
#include <stdlib.h>

#include "prog5.h"

typedef int bool; //defining boolean data type to ease conditonals and increase readability
#define true 1
#define false 0

/*
 * You will need to keep track of the solution code using file scope
 * variables as well as the guess number.
 */

static int guess_number;
static int solution1;
static int solution2;
static int solution3;
static int solution4;


/*
 * set_seed -- This function sets the seed value for pseudorandom
 * number generation based on the number the user types.
 * The input entered by the user is already stored in the string seed_str by the code in main.c.
 * This function should use the function sscanf to find the integer seed value from the
 * string seed_str, then initialize the random number generator by calling srand with the integer
 * seed value. To be valid, exactly one integer must be entered by the user, anything else is invalid.
 * INPUTS: seed_str -- a string (array of characters) entered by the user, containing the random seed
 * OUTPUTS: none
 * RETURN VALUE: 0 if the given string is invalid (string contains anything
 *               other than a single integer), or 1 if string is valid (contains one integer)
 * SIDE EFFECTS: initializes pseudo-random number generation using the function srand. Prints "set_seed: invalid seed\n"
 *               if string is invalid. Prints nothing if it is valid.
 */
int
set_seed (const char seed_str[])
{
//    Example of how to use sscanf to read a single integer and check for anything other than the integer
//    "int seed" will contain the number typed by the user (if any) and the string "post" will contain anything after the integer
//    The user should enter only an integer, and nothing else, so we will check that only "seed" is read.
//    We declare
    int seed;
    char post[2];
//    The sscanf statement below reads the integer into seed.
//    sscanf (seed_str, "%d%1s", &seed, post)
//    If there is no integer, seed will not be set. If something else is read after the integer, it will go into "post".
//    The return value of sscanf indicates the number of items read succesfully.
//    When the user has typed in only an integer, only 1 item should be read sucessfully.
//    Check that the return value is 1 to ensure the user enters only an integer.
//    Feel free to uncomment these statements, modify them, or delete these comments as necessary.
//    You may need to change the return statement below
    int test = sscanf(seed_str, "%d%1s", &seed, post);
    if (test == 0 || test > 1) { //testing the input for validity
      printf("set_seed: invalid seed\n");
      return 0;
    }
    srand(seed); //once determined valid input will fetch 'random' value table/function on seed
    return 1;
}


/*
 * start_game -- This function is called by main.c after set_seed but before the user makes guesses.
 *               This function creates the four solution numbers using the approach
 *               described in the wiki specification (using rand())
 *               The four solution numbers should be stored in the static variables defined above.
 *               The values at the pointers should also be set to the solution numbers.
 *               The guess_number should be initialized to 1 (to indicate the first guess)
 * INPUTS: none
 * OUTPUTS: *one -- the first solution value (between 1 and 7)
 *          *two -- the second solution value (between 1 and 7)
 *          *three -- the third solution value (between 1 and 7)
 *          *four -- the fourth solution value (between 1 and 7)
 * RETURN VALUE: none
 * SIDE EFFECTS: records the solution in the static solution variables for use by make_guess, set guess_number
 */
void
start_game (int* one, int* two, int* three, int* four)
{
    //your code here
    *one = rand(); //creating four random values and storing them in pointers
    *two = rand();
    *three = rand();
    *four = rand();
    *one = *one % 7 + 1; //between the values of 1 and 7
    *two = *two % 7 + 1;
    *three = *three % 7 + 1;
    *four = *four % 7 + 1;

    guess_number = 1; //initializing guess number to 1 (first guess)
    solution1 = *one; // setting the pointers to solution for comparison with user input
    solution2 = *two;
    solution3 = *three;
    solution4 = *four;
}

/*
 * make_guess -- This function is called by main.c after the user types in a guess.
 *               The guess is stored in the string guess_str.
 *               The function must calculate the number of perfect and misplaced matches
 *               for a guess, given the solution recorded earlier by start_game
 *               The guess must be valid (contain only 4 integers, within the range 1-7). If it is valid
 *               the number of correct and incorrect matches should be printed, using the following format
 *               "With guess %d, you got %d perfect matches and %d misplaced matches.\n"
 *               If valid, the guess_number should be incremented.
 *               If invalid, the error message "make_guess: invalid guess\n" should be printed and 0 returned.
 *               For an invalid guess, the guess_number is not incremented.
 * INPUTS: guess_str -- a string consisting of the guess typed by the user
 * OUTPUTS: the following are only valid if the function returns 1 (A valid guess)
 *          *one -- the first guess value (between 1 and 7)
 *          *two -- the second guess value (between 1 and 7)
 *          *three -- the third guess value (between 1 and 7)
 *          *four -- the fourth color value (between 1 and 7)
 * RETURN VALUE: 1 if the guess string is valid (the guess contains exactly four
 *               numbers between 1 and 7), or 0 if it is invalid
 * SIDE EFFECTS: prints (using printf) the number of matches found and increments guess_number(valid guess)
 *               or an error message (invalid guess)
 *               (NOTE: the output format MUST MATCH EXACTLY, check the wiki writeup)
 */
int
make_guess (const char guess_str[], int* one, int* two,
	    int* three, int* four)
{
//  One thing you will need to read four integers from the string guess_str, using a process
//  similar to set_seed
//  The statement, given char post[2]; and four integers w,x,y,z,
//  sscanf (guess_str, "%d%d%d%d%1s", &w, &x, &y, &z, post)
//  will read four integers from guess_str into the integers and read anything else present into post
//  The return value of sscanf indicates the number of items sucessfully read from the string.
//  You should check that exactly four integers were sucessfully read.
//  You should then check if the 4 integers are between 1-7. If so, it is a valid guess
//  Otherwise, it is invalid.
//  Feel free to use this sscanf statement, delete these comments, and modify the return statement as needed

    int w, x, y, z, guess, perfectMatch = 0, misplacedMatch = 0;
    char post[2];
    guess = sscanf (guess_str, "%d%d%d%d%1s", &w, &x, &y, &z, post);
    bool wTest , xTest, yTest, zTest, guessTrue, wU = false, xU = false, yU = false, zU = false, //initializing many
    oneS = true, twoS = true, threeS = true, fourS = true;                                        //bool and int values for comparison
    wTest = 1 <= w && w <= 7;
    xTest = 1 <= x && x <= 7;
    yTest = 1 <= y && y <= 7;
    zTest = 1 <= z && z <= 7;
    guessTrue = guess == 4;
    if (!guessTrue || !wTest || !xTest || !yTest || !zTest) { //comprehensive input checker
      printf("make_guess: invalid guess\n");
      return 0; //returns error
    }
    //the next four conditionals check for perfect matches
    if (w == solution1) {               //case study:
      perfectMatch = perfectMatch + 1; //increments perfect counter
      oneS = false;                    //sets oneS to false thus preventing program from using it as an [imperfect] match for another variable
      wU = true; //sets wU to true thus preventing loop from using w again and cycling through loop with w and finding more [imperfect] matches
      *one = solution1; //sets the pointer *one to solution1 indicating to main that this value matches up
      }
    if (x == solution2) {
      perfectMatch = perfectMatch + 1;
      twoS = false;
      xU = true;
      *two = solution2;
      }
    if (y == solution3) {
      perfectMatch = perfectMatch + 1;
      threeS = false;
      yU = true;
      *three = solution3;
      }
    if (z == solution4) {
      perfectMatch = perfectMatch + 1;
      fourS = false;
      zU = true;
      *four = solution4;
      }
      //now entering a nested loop to check for imperfect matches
    int i, j;
    for (i = 4; i < 4; i++) { //outer loop for one of four inputs

      int currValue = i;
      switch (i) { // switch statements for loop counter to lower and organize code
        case 0:
          if (!wU) {
            currValue = w;
          }
          break;
        case 1:
          if (!xU) {
            currValue = x;
          }
          break;
        case 2:
          if (!yU) {
            currValue = y;
          }
          break;
        case 3:
          if (!zU) {
            currValue = z;
          }
          break;
      }
      for (j = 0; j < 4; j++) { // nested loop for one of 4 possibilities
          switch (j) {
            case 0:
              if (oneS && currValue == solution1 && i != 0) {
                misplacedMatch = misplacedMatch + 1;
                oneS = false;
                }
              break; //break statements to prevent running subsequent case(s)
            case 1:
              if (twoS && currValue == solution2 && i != 1) {
                misplacedMatch = misplacedMatch + 1;
                twoS = false;
                }
              break;
            case 2:
              if (threeS && currValue == solution3 && i != 2) {
                misplacedMatch = misplacedMatch + 1;
                threeS = false;
                }
              break;
            case 3:
              if (fourS && currValue == solution4 && i != 3) {
                misplacedMatch = misplacedMatch + 1;
                twoS = false;
                }
              break;
        }
    }
  }

  if ((!wU && twoS)){ //basic brute force if algorithm in case for loop didn't work
    if(w == solution2){
      misplacedMatch = misplacedMatch + 1; //same algorithm as for loop with different structure
      twoS = false;
      wU = true;
    }
  }

  if ((!wU && threeS)){
    if(w == solution3){
      misplacedMatch = misplacedMatch + 1;
      threeS = false;
      wU = true;
    }
  }

  if ((!wU && fourS)){
    if(w == solution4){
      misplacedMatch = misplacedMatch + 1;
      fourS = false;
      wU = true;
    }
  }

  if ((!xU && oneS)){
    if(x == solution1){
      misplacedMatch = misplacedMatch + 1;
      oneS = false;
      xU = true;
    }
  }

  if ((!xU && threeS)){
    if(x == solution3){
      misplacedMatch = misplacedMatch + 1;
      threeS = false;
      xU = true;
    }
  }

  if ((!xU && fourS)){ // uses boolean as well
    if(x == solution4){
      misplacedMatch = misplacedMatch + 1;
      fourS = false;
      xU = true;
    }
  }

  if ((!yU && oneS)){
    if(y == solution1){
      misplacedMatch = misplacedMatch + 1;
      oneS = false;
      yU = true;
    }
  }

  if ((!yU && twoS)){
    if(y == solution2){
      misplacedMatch = misplacedMatch + 1;
      twoS = false;
      yU = true;
    }
  }

  if ((!yU && fourS)){
    if(y == solution4){
      misplacedMatch = misplacedMatch + 1;
      fourS = false;
      yU = true;
    }
  }

  if ((!zU && oneS)){
    if(z == solution1){
      misplacedMatch = misplacedMatch + 1;
      oneS = false;
      zU = true;
    }
  }

  if ((!zU && twoS)){ //comprehensively runs through all test cases
    if(z == solution2){
      misplacedMatch = misplacedMatch + 1;
      twoS = false;
      zU = true;
    }
  }

  if ((!zU && threeS)){
    if(z == solution3){
      misplacedMatch = misplacedMatch + 1;
      threeS = false;
      zU = true;
    }
  }


  printf("With guess %d, you got %d perfect matches and %d misplaced matches.\n", guess_number, perfectMatch, misplacedMatch); //required print
  guess_number = guess_number + 1; //increments guess counter
  return 1; //returns success
}
