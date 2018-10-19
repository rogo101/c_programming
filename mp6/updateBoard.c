
/* In this C program, we were able to implement three functions in order to
successfully program the game of life. The function countLiveNeighbor counts the
number of ones around a specific element. We used loops to itrate it through the
corners and edges, The second function updates the board in relation to neighbors
around the element.
ishanj2 pujithb2 raghavv2
*/

typedef int bool;
#define true 1;
#define false 0;
//defining an object bool for convenience
int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
  int i, j; //iterators through row and column
  int number = 0; // number is count
  bool a = row == 0;
  bool b = col == 0;
  bool c = board[boardColSize]==1;
  bool d = board[boardColSize+1]==1; //bool values for convenience
  bool e = board[boardColSize*row+(col-1)]==1;
  bool f = board[boardColSize*(row+1)+col]==1;
  bool g = board[boardColSize*(row+1)+(col-1)]==1;

//checks corners with return order
  if (a && b){
    if(board[1]==1 || c || d){
      number++;
    }
    return number;
  }

  if (a && col==(boardColSize-1)){
    if(e || f || g){
      number++;
    }
    return number;
  }

  if (row==(boardRowSize-1) && b){
    if(board[boardColSize*row+(col+1)]==1 || board[boardColSize*(row-1)+col]==1 || board[boardColSize*(row-1)+(col+1)]==1){
      number++;
    }
    return number;
  }

  if(row==(boardRowSize-1) && col==(boardColSize-1)){
    if(e || board[boardColSize*(row-1)+col]==1 || board[boardColSize*(row-1)+(col-1)]==1){
      number++;
    }
    return number;
  }

//checks edges
  if(a){
    for (j=-1; j<2; j++){
      if (board[boardColSize*(row+1)+(col+j)]==1){
        number++;
      }
    }
    for(i=-1; i<2; i++){
      if (board[boardColSize*(row)+(col+i)]==1  && i != 0){
        number++;
      }
    }
    return number;
  }

  if (row==boardRowSize-1){
    bool transmit = true;
    for (j=-1; j<2; j++){
      if (board[boardColSize*(row-1)+(col+j)]==1){
        number++;
      }
    }
    for(i=-1; i<2; i++){
      if (i==0){
        transmit = false;
      }
      if (transmit && board[boardColSize*(row)+(col+i)]==1){
        number++;
      }
    }
    return number;
  }

  if(b){
    for(i=1; i<2; i++){
      if (board[boardColSize*row+(col+i)]==1){
        number++;
      }
    }
    if(f || board[boardColSize*(row+1)+col+1]==1 || board[boardColSize*(row-1)+col]==1 || board[boardColSize*(row-1)+col+1]==1){
      number++;
    }
    return number;
    }

  if(col==boardColSize-1){
    for(i=1; i<2; i++){
      if (board[boardColSize*row+(col-i)]==1){
        number++;
      }
    }
//checks rest in the middle
    if(f || board[boardColSize*(row+1)+col-1]==1 || board[boardColSize*(row-1)+col]==1 || board[boardColSize*(row-1)+col-1]==1){
      number++;
    }
    return number;
    }

  else {
    for (j=-1; j<2; j++){
      if(board[boardColSize*(row+1)+(col+j)]==1){
        number++;
      }
    }
    }
    for(i=-1; i<2; i++){
      if(board[boardColSize*row +(col+i)]==1 && i!= 0){
        number++;
      }
    }
      for (j=-1; j<2; j++){
        if(board[boardColSize*(row-1)+(col+j)]==1){
          number++;
        }
    }
    return number++;
}

void updateBoard(int* board, int boardRowSize, int boardColSize) {
	int i, j;
	int arr[boardRowSize * boardColSize];
//goes through the array
  for (i=0; i<boardRowSize; i++){
		for(j=0; j<boardColSize; j++){
			if(board[boardColSize*i+j]==1){
				if (countLiveNeighbor(board, boardRowSize, boardColSize, i, j)<2 || countLiveNeighbor(board, boardRowSize, boardColSize, i, j)>3){
						arr[boardColSize*i+j]=0;
				}
				if (countLiveNeighbor(board, boardRowSize, boardColSize, i, j)==2 || countLiveNeighbor(board, boardRowSize, boardColSize, i, j)==3){
					arr[boardColSize*i+j]=1;
				}
			}
			else {
				if (countLiveNeighbor(board, boardRowSize, boardColSize, i, j)==3){
					arr[boardColSize*i+j]=1;
				}
			else
				arr[boardColSize*i+j]=0;
			}
		}
	}
	for (i=0; i<boardRowSize; i++) {
		for(j=0; j<boardColSize; j++){
			board[boardColSize*i+j]=arr[boardColSize*i+j];
		}
}
}

int aliveStable(int* board, int boardRowSize, int boardColSize){
	int status_alive=1;//checks if status has changed on each cell indiviaully
	int i, j;

	for (i=0; i<boardRowSize; i++)
		for(j=0; j<boardColSize; j++){
			if(board[boardColSize*i+j]==1){
				if (countLiveNeighbor(board, boardRowSize, boardColSize, i, j)<2 || countLiveNeighbor(board, boardRowSize, boardColSize, i, j)>3){
						status_alive=0;
				}
				if (countLiveNeighbor(board, boardRowSize, boardColSize, i, j)==2 || countLiveNeighbor(board, boardRowSize, boardColSize, i, j)==3){
					board[boardColSize*i+j]=1;
				}
			}
			else {
				if (countLiveNeighbor(board, boardRowSize, boardColSize, i, j)==3){
					status_alive=0;
				}
			}
		}
		return status_alive;
}
