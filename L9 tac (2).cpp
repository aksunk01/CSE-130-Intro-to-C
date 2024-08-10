#include <iostream>
#include <cstdlib>
#include <ctime>

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        // Initialize the board
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }

        // Randomly decide who goes first
        srand(static_cast<unsigned int>(time(0)));
        currentPlayer = (rand() % 2 == 0) ? 'X' : 'O';
    }

    void Board() const {
        // Display the Tic-Tac-Toe board
        std::cout << "  1 2 3\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i + 1 << ' ';
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                if (j < 2) std::cout << '|';
            }
            std::cout << '\n';
            if (i < 2) std::cout << "  -----\n";
        }
        std::cout << "\n";
    }

    bool isBoardFull() const {
        // Check if the board is full
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    bool makeMove(int row, int col) {
        // Make a move and check if it's legal
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            std::cout << "Illegal move. Try again.\n";
            return false;
        }

        board[row - 1][col - 1] = currentPlayer;
        return true;
    }

    bool checkWin() const {
        // Check for a win horizontally, vertically, or diagonally
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true; // Horizontal win
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true; // Vertical win
            }
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true; // Diagonal win (top-left to bottom-right)
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true; // Diagonal win (top-right to bottom-left)
        }

        return false; // No win
    }

    void switchPlayer() {
        // Switch the current player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() const {
        // Get the current player
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;

    do {
        game.Board();
        int row, col;
        char currentPlayer = game.getCurrentPlayer();

        if (currentPlayer == 'X') {
            std::cout << "Your turn. Enter row (1-3) and column (1-3): ";
            std::cin >> row >> col;
        } else {
            std::cout << "Computer's turn\n";
            row = rand() % 3 + 1;
            col = rand() % 3 + 1;
        }

        if (game.makeMove(row, col)) {
            if (game.checkWin()) {
                game.Board();
                std::cout << currentPlayer << " wins!\n";
                break;
            } else if (game.isBoardFull()) {
                game.Board();
                std::cout << "It's a draw!\n";
                break;
            }

            game.switchPlayer();
        }

    } while (true);

    return 0;
}