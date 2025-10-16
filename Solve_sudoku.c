#include <stdio.h>
// Assuming a given Sudoku solver
// Need to add functionality to take in a sudoku puzzle from user input
int puzzle[9][9] = {
  {3,0,0,0,2,0,0,7,0},
  {9,0,0,5,0,0,0,1,4},
  {0,1,6,3,7,0,0,0,8},
  {2,0,0,8,0,0,0,0,1},
  {5,0,0,0,4,1,8,0,0},
  {0,8,9,0,0,0,0,5,0},
  {0,0,5,0,1,0,2,8,0},
  {0,4,0,0,0,6,0,9,3},
  {7,3,1,0,8,2,0,0,0},
}; // 0 indicates a blank cell in the puzzle

void printPuzzle(int puzzle[9][9]); // Prints the final solved sudoku
int validPuzzle(int puzzle[9][9], int row, int col, int val); // Checks validity when 'val' is placed in puzzle[row][col]



int main() {
  printf("\n WELCOME TO SUDOKU SOLVER\n");
  printf("Original Puzzle : ");
  printPuzzle(puzzle);
  // Checking validPuzzle- place desired values of val in puzzle[row][col]
  int valid = validPuzzle(puzzle, 0, 1, 5);
  if (valid == 1) {
    printf("\n VALID MOVE\n");
  } else printf("\n INVALID MOVE\n");

  return 0;
}

void printPuzzle(int puzzle[9][9]) {
  printf("\n+-------+-------+-------+");
  for (int row = 0; row < 9; row++) {
    if (row % 3 == 0 && row != 0) {
      printf("\n|-------+-------+-------|");
    }
    printf("\n");
    for (int col = 0; col < 9; col++) {
      if (col % 3 == 0) {
        printf("| ");
      }
      if (puzzle[row][col] != 0) {
        printf("%d ", puzzle[row][col]);
      } else {
        printf("  ");
      }
    }
    printf("|");
  }
  printf("\n+-------+-------+-------+\n");
}

int validPuzzle(int puzzle[9][9], int row, int col, int val) {

  // CHECK valid row
  for (int i = 0; i < 9; i++) {
    if (puzzle[row][i] == val) {
      return 0; // INVALID ROW 
      break;
    }
  }

  // CHECK valid column
  for (int i = 0; i < 9; i++) {
    if (puzzle[i][col] == val) {
      return 0; // INVALID COLUMN
      break;
    } 
  }

  // CHECK valid square
  int r = row - row % 3;
  int c = col - col % 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (puzzle[r+i][c+j] == val) {
        return 0; // INVALID SQUARE
      }
    }
  }

  return 1; // vALID MOVE
}