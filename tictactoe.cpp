#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer = 'X';

void initializeBoard() {
    char start = '1';
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = start++;
        }
    }
}

void drawBoard() {
    system("clear"); // for Linux/Unix, use system("cls"); for Windows
    cout << "Tic Tac Toe Game" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "--+---+--" << endl;
    }
}

bool isMoveValid(int move) {
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    return move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O';
}

void makeMove(int move) {
    int row = (move - 1) / SIZE;
    int col = (move - 1) % SIZE;
    board[row][col] = currentPlayer;
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return choice == 'y' || choice == 'Y';
}

int main() {
    int move;
    bool gameWon = false;

    do {
        initializeBoard();
        currentPlayer = 'X';
        gameWon = false;

        while (true) {
            drawBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (isMoveValid(move)) {
                makeMove(move);
                gameWon = checkWin();

                if (gameWon) {
                    drawBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                } else if (isBoardFull()) {
                    drawBoard();
                    cout << "It's a draw!" << endl;
                    break;
                }

                switchPlayer();
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    } while (playAgain());

    cout << "Thank you for playing!" << endl;
    return 0;
}
