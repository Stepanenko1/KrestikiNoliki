#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 4; 

void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "---+---+---+" << endl; 
    }
}

bool isDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (board[i][j] == ' ') 
                return false;
    return true;
}

int main() {
    vector<vector<char>> board(SIZE, vector<char>(SIZE, '-')); 

    char currentPlayer = '*'; 

    bool gameEnd = false;

    while (!gameEnd) {
        printBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        board[row - 1][col - 1] = currentPlayer;

        if (isWinning(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameEnd = true;
        }
        else if (isDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            gameEnd = true;
        }
        else {
            currentPlayer = (currentPlayer == '*') ? '@' : '*'; 
        }
    }

    return 0;
}
