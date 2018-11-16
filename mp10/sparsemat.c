/*
We created a mp that creates a more efficient way to store sparse matrices.
This is rather than using a 2-D array. 
We are storing all the non zero values from the sparse matrix.
Then adding and multiplying resptively
to incorporate all the zero components.
raghavv2 ishanj2 pujithb2
*/

#include "sparsemat.h"

#include <stdio.h>
#include <stdlib.h>





sp_tuples * load_tuples(char* input_file)
{

    return NULL;
}



double gv_tuples(sp_tuples * mat_t,int row,int col)

{   sp_tuples_node * curr = mat_t -> tuples_head;//going into function sp_tuples
    int i;
    for (i = 0; i < mat_t -> nz; i++) {//traverses through sparse matriix
        if (curr -> row == row && curr -> col == col) {//checking values
          return curr -> value;//returning them if they match
        }
        curr = curr -> next;
    }
    return 0;
}



void set_tuples(sp_tuples * mat_t, int row, int col, double value)
{
    sp_tuples_node * head = mat_t -> tuples_head;
    sp_tuples_node * curr = head;
    int i;
    if (value == 0) {
      for (i = 0; i < mat_t -> nz; i++) {
          if (curr -> next -> row == row && curr -> next -> col == col) {
            curr -> next = curr -> next -> next;
            mat_t -> tuples_head = head;
            mat_t -> nz = (mat_t -> nz) - 1;
            break;
          }
          curr = curr -> next;
      }
    }
    else {
      int found = 0;
      for (i = 0; i < mat_t -> nz; i++) {
          if (curr -> row == row && curr -> col == col) {
            curr -> value == value;
            mat_t -> tuples_head = head;
            found = 1;
            break;
          }
          curr = curr -> next;
      }
      if (found == 0) {
        while (curr -> next != NULL) {
          curr = curr -> next;
        }
        sp_tuples_node * insert;
        insert -> value = value;
        insert -> row = row;
        insert -> col = col;
        curr -> next = insert;
        mat_t -> tuples_head = head;
      }
    }

}



void save_tuples(char * file_name, sp_tuples * mat_t)
{

	return;
}



sp_tuples * add_tuples(sp_tuples * matA, sp_tuples * matB){

	return NULL;
}



sp_tuples * mult_tuples(sp_tuples * matA, sp_tuples * matB){
    return NULL;

}



void destroy_tuples(sp_tuples * mat_t){

    return;
}
