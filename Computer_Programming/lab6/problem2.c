#include <stdio.h>

#define BOARD_SIZE 8

int main() {
    char chessboard[BOARD_SIZE][BOARD_SIZE];
    int row, col;

    // Initialize the chessboard pattern
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                chessboard[row][col] = 'W';
            } else {
                chessboard[row][col] = 'B';
            }
        }
    }

    // Display the chessboard pattern
    printf("Chessboard Pattern:\n");
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", chessboard[row][col]);
        }
        printf("\n");
    }

    return 0;
}