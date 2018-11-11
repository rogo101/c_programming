/* The following program takes an input file in the form of a maze.
It uses File I/O to make sense of it. Then it uses depth first search to recursively
solve the file. Once completed the solution is printed with a * for correct PATH
and ~ for incorrect. Also the validity of solution is displaed.
raghavv2 ishanj2 pujithb2
*/

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"


/*
 * createMaze -- Creates and fills a maze structure from the given file
 * INPUTS:       fileName - character array containing the name of the maze file
 * OUTPUTS:      None
 * RETURN:       A filled maze structure that represents the contents of the input file
 * SIDE EFFECTS: None
 */
maze_t * createMaze(char * fileName)
{
     FILE * fileMaze = fopen(fileName, "r"); //opens file to read
     maze_t * location = malloc(sizeof(*location)); //dynamically allocated pointer to maze_t location
     int rows = 0;
     int cols = 0;
     fscanf(fileMaze, "%d %d\n", &rows, &cols); // gets rows and cols values
     location -> height = rows; //sets them equal to maze_t struct values
     location -> width = cols;
     location -> cells = malloc((rows)*sizeof(char*));
     int i = 0;
     for(i = 0; i < rows; i++){
       location -> cells[i] = malloc(cols*sizeof(char)); //following scans the maze shape and boundaries to the struct
     }
     int j = 0;
     char character;
     for(i=0; i<(rows); i++){
       for(j=0; j<(cols); j++){
         fscanf(fileMaze, "%c", &character);
         location -> cells[i][j]=character;
       }
       fscanf(fileMaze,"%c", &character);
     }

     for(i = 0; i < location -> height; i++){
       for(j = 0; j < location -> width; j++){
         if((location -> cells[i][j]) == START){
           location -> startRow = i;
           location -> startColumn = j;
         }
         else if((location -> cells[i][j]) == END){
           location -> endRow = i;
           location -> endColumn=j;
         }
         else {
           continue;
         }
       }
     }
     fclose(fileMaze); //closes file
     return location; //returns pointer to configured maze struct
}

/*
 * destroyMaze -- Frees all memory associated with the maze structure, including the structure itself
 * INPUTS:        maze -- pointer to maze structure that contains all necessary information
 * OUTPUTS:       None
 * RETURN:        None
 * SIDE EFFECTS:  All memory that has been allocated for the maze is freed
 */
void destroyMaze(maze_t * maze)
{
    // Your code here.

    int i = 0;
    while (i < maze -> height) {
      free(maze -> cells[i]); //frees memory of maze through iteration
      i++;
    }
    free(maze -> cells);
    free(maze); //frees struct memory itself

}

/*
 * printMaze --  Prints out the maze in a human readable format (should look like examples)
 * INPUTS:       maze -- pointer to maze structure that contains all necessary information
 *               width -- width of the maze
 *               height -- height of the maze
 * OUTPUTS:      None
 * RETURN:       None
 * SIDE EFFECTS: Prints the maze to the console
 */
void printMaze(maze_t * maze)
{
    // Your code here.

    int j = 0, i = 0;
    for(i = 0; i < maze -> height; i++){
       for(j = 0; j < maze -> width; j++){
            printf("%c", maze -> cells[i][j]); //iterates to print maze
       }
       printf("\n"); // new line
     }

}

/*
 * solveMazeDFS -- recursively solves the maze using depth first search,
 * INPUTS:               maze -- pointer to maze structure with all necessary maze information
 *                       col -- the column of the cell currently beinging visited within the maze
 *                       row -- the row of the cell currently being visited within the maze
 * OUTPUTS:              None
 * RETURNS:              0 if the maze is unsolvable, 1 if it is solved
 * SIDE EFFECTS:         Marks maze cells as visited or part of the solution path
 */
int solveMazeDFS(maze_t * maze, int col, int row)
{

   if(!(maze -> cells[row][col] == START)){ //testing a lot of edge cases
     if ((row >= maze -> height || row < 0 || col  >= maze -> width || col < 0))  {
       return 0;
     }
     if (maze -> cells[row][col] == END){
       maze -> cells[maze -> startRow][maze -> startColumn] = START;
       return 1;
      }
     if(maze -> cells[row][col] != START){
       if (maze -> cells[row][col] == WALL || maze -> cells[row][col] != EMPTY || maze -> cells[row][col] == VISITED) {
       return 0;
     }
   }
  }

  maze -> cells[row][col] = PATH;
  if(solveMazeDFS(maze,col, row - 1) == 1 || solveMazeDFS(maze, col - 1, row) == 1 || solveMazeDFS(maze,col, row+1) == 1 || solveMazeDFS(maze, col + 1, row) == 1) {
    return 1; //recursively goes through maze
  }

  if (!(maze -> cells[row][col] == START)) {
    maze -> cells[row][col] = VISITED;
  }

  return 0; //returns if fails - maze is unsolvable

}
