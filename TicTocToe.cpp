#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char >> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void printBoard() {
        cout << "Current board:\n";
        for (int i = 0; i < 3; ++i) {
            cout << "|";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << "|";
            }
            cout << endl;
            cout << "-----\n";
        }
    }

    bool isWinner() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    bool isBoardFull() {
        for (const auto &row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        int row, col;
        while (true) {
            printBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Validate input
            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            // Place the mark on the board
            board[row][col] = currentPlayer;

            // Check for a winner
            if (isWinner()) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check for a draw
            if (isBoardFull()) {
                printBoard();
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players
            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
