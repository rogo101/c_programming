#include "sudoku.h"

/* In this MP, we created a sudoku solver using a few key functions. The checker functions see if an input is valid.
There are three functions to see if valid in row, column, 3x3, respectively and then a whole checker function to check in
each of these areas. The sudoku solver then uses the validity ofcthese inputs and solves the puzzle.
raghavv2 ishanj2 pujithb2*/

//-------------------------------------------------------------------------------------------------
// Start here to work on your MP7
//-------------------------------------------------------------------------------------------------

// You are free to declare any private functions if needed.

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);

  // BEG TODO
  int j = 0;
  while (j < 9) {
    if (sudoku[i][j] == val){ //checks to see if input is valid in row
      return 1;
    }
    j++; //incrementing opperator
  }
  return 0;
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);

  // BEG TODO
  int i = 0;
  while (i < 9) {
    if (sudoku[i][j] == val){ //checks to see if input is valid in column
      return 1;
    }
    i++;
  }
  return 0;
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9);
  int count = 3, a , b, val1, val2;
  // BEG TODO
  val2 = 3; //constant value
  while (count != 0) { //cycles through each section of 3x3 zone

    if (count == 3) {
      val1 = 0; //change of values
    }
    else if (count == 2) {
      val1 = 3;
    }
    else {
      val1 = 6;
    }

    if(i >= val1 == true && i < (val1 + 3) == true) {
      if(j >= (val2 - 3) == true && j < val2 == true){
        for (a = val1; a < (val1 + 3); a++) {
          for (b = (val2 - 3); b < val2; b++) {
            if (val == sudoku[a][b]) {
              return 1;
            }
          }
        }
      }
      if(j >= val2 == true && j < (val2+3) == true) {
        for (a = val1; a < (val1 + 3); a++){ //nested loop
          for (b = val2; b < (val2 + 3); b++){
            if (val == sudoku[a][b]){
              return 1; //returns true
            }
          }
        }
      }
      if (j >= (val2+3) == true && j < (val2 + 6) == true) {
          for (a = val1; a < (val1 + 3); a++){
              for (b = (val2 + 3); b < (val2 + 6); b++){
                if (val == sudoku[a][b]){
                  return 1;
                }
              }
            }
          }
        }
      count--;
  }
  return 0;
  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);

  // BEG TODO
  if (is_val_in_col(val,j, sudoku) == 1) {
    return 0;
  }
  if (is_val_in_row(val,i,sudoku) == 1){
    return 0;
  }
  if (is_val_in_3x3_zone(val,i,j,sudoku) == 1) {
    return 0;
  }
  return 1;
  // END TODO
}

// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {

  // BEG TODO.
  int temp = 1, top = 9, i, j, row, column;
  for (i = 0; i < top; i++){
      for (j = 0; j < top; j++){
         if (sudoku[i][j] == 0){
           temp = 0;
           row = i;
           column = j;
           break; //breaks out if value is 0
          }
         }
         if (temp <= 0){
           break; //another break necesary to fully leave. Sudoku is unsolved.
         }
       }
  if (temp == 1) {
    return 1; //if temp is = 1 then no zero values returns 1 as solved sudoku
  }
  for (temp = 1; temp <= top; temp++){
      if (is_val_valid(temp, row, column, sudoku) == 1){ //checks to see if temp works
         sudoku[row][column] = temp; //sets equal if works
         if(solve_sudoku(sudoku)){ //checks to see if sudoku is solved
          return 1;
         }
         else {
          sudoku[row][column] = 0; //if not sets value back to 0 and tries again
        }
      }
    }
  return 0;  //if unsolvable returns 0
      // END TODO.
}

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}
