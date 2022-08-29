#include <stdio.h>
#include <stdlib.h>

void printBoard(int **board, int rows, int cols);

int **initBoard(int rows, int cols);

int checkRow(int **board, int cols, int row, int num);
int checkCol(int **board, int rows, int col, int num);
int checkSquare(int **board, int row, int col, int num);
int isSafe(int **board, int rows, int cols, int row, int col, int num);
int findUnassigned(int **board, int rows, int cols, int *row, int *col);
int solveBoard(int **board, int rows, int cols);

int main(int argc, char *argv[]) {
	int rows;
	int cols;

	// get number of rows and columns
	// 
	//
	// need to make sure that rows and cols are divisible by 3
	printf("Enter Number of rows and cols seperated by a space ex.(row col): ");
	scanf("%d %d", &rows, &cols);
	printf("rows: %d cols: %d\n", rows, cols);

	// initialize board and fill with user input
	int **board = initBoard(rows, cols);
	printBoard(board, rows, cols);

	if(solveBoard(board, rows, cols) == 1) {
		printf("\nSolved!");
		printBoard(board, rows, cols);
	}
	else{
		printf("No solution exists\n");
	}


	exit(0);
}

/*
 * Checks if the given row contains the given number
 * If it does, then return 0, otherwise return 1 indicating that num is valid
 */

int checkRow(int **board, int cols, int row, int num) {
	for(int col = 0; col < cols; col++) {
		if(board[row][col] == num) {
			return 0;
		}
	}

	return 1;
}

int checkCol(int **board, int rows, int col, int num) {
	for(int row = 0; row < rows; row++) {
		if(board[row][col] == num) {
			return 0;
		}
	}

	return 1;
}

int checkSquare(int **board, int row, int col, int num) {
	// get the starting row and column index of the 3x3 square being checked
	// (top left corner of the 3x3 square being checked)
	int squareRowIndex = (row / 3) * 3;
	int squareColIndex = (col / 3) * 3;

	for(int row = squareRowIndex; row < squareRowIndex + 3; row++) {
		for(int col = squareColIndex; col < squareColIndex + 3; col++) {
			if(board[row][col] == num) {
				return 0;
			}
		}
	}

	return 1;
}

int isSafe(int **board, int rows, int cols, int row, int col, int num) {
	return checkRow(board, cols, row, num) && checkCol(board, rows, col, num) && checkSquare(board, row, col, num);
}

int findUnassigned(int **board, int rows, int cols, int *row, int *col) {
	for(*row = 0; *row < rows; (*row)++) {
		for(*col = 0; *col < cols; (*col)++) {
			if(board[*row][*col] == 0) {
				return 1;
			}
		}
	}
	return 0;
}

int solveBoard(int **board, int rows, int cols) {
	int row;
	int col;

	if(findUnassigned(board, rows, cols, &row, &col) == 0) {
		return 1;
	}

	for(int num = 1; num <= 9; num++) {
		if(isSafe(board, rows, cols, row, col, num) == 1) {
			board[row][col] = num;
			if(solveBoard(board, rows, cols) == 1) {
				return 1;
			}
			board[row][col] = 0;
		}
	}
	return 0;
}

// TODO: describe method
int **initBoard(int rows, int cols) {
	// create 2d board with pointers to pointers
	int **board = (int**)malloc(rows * sizeof(int*));
	for(int n = 0; n < rows; n++) {
		board[n] = (int*)malloc(cols * sizeof(int));
	}

	// get user input and fill the board
	printf("Seperate nums by a space, use 0 for empty cells\n");
	for(int i = 0; i < cols; i++) {
		printf("Enter row %d: ", i+1);
		int num;
		for(int j = 0; j < rows; j++) {
			scanf("%d", &num);
			board[i][j] = num;
		}
	}
	return board;
}

void printBoard(int **board, int rows, int cols) {
	printf("\n");
	for(int row = 0; row < rows; row++) {
		if(row % 3 == 0 && row != 0) {
			printf("\n");
		}
		for(int col = 0; col < cols; col++) {
			if(col % 3 == 0 && col != 0) {
				printf(" ");
			}
			if(board[row][col] != 0) {
				printf("%d ", board[row][col]);	
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
}
