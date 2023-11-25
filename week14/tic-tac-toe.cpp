#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board with numbered spaces
void printBoard(const vector<char>& board) {
    cout << " 1 | 2 | 3 " << endl;
    cout << "-----------" << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "-----------" << endl;
    cout << " 7 | 8 | 9 " << endl;

    cout << "Current Board:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int index = 3 * i + j;
            if (board[index] == 'X' || board[index] == 'O') {
                cout << " " << board[index] << " ";
            } else {
                cout << " " << index + 1 << " ";
            }
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "-----------" << endl;
    }
}

// Function to check for a winner
bool checkWinner(const vector<char>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true; //check for columns
        }
        if (board[3 * i] == player && board[3 * i + 1] == player && board[3 * i + 2] == player) {
            return true; //check for rows
        }
    }
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true; //diagonal top-left to bottom right
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;  //diagonal from top-right to bottom-left
    }
    return false;
}

int main() {
    vector<char> board(9, ' ');

    char currentPlayer = 'X';
    int move;
    int moves = 0;

    cout << endl;

    while (true) {
        // Display the board
        printBoard(board);

        // Input and validate player's move
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || board[move - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the board
        board[move - 1] = currentPlayer;
        moves++;

        // Check for a winner or a draw
        if (checkWinner(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            break;
        } else if (moves == 9) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
