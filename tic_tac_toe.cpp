#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;

void resetBoard() {
    char initial = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = initial++;
        }
    }
}

void drawBoard() {
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;
}

void switchPlayer() {
    current_player = (current_player == 1) ? 2 : 1;
    current_marker = (current_marker == 'X') ? 'O' : 'X';
}

void game() {
    resetBoard();
    current_marker = 'X';
    current_player = 1;
    int player_won;

    for (int i = 0; i < 9; i++) {
        drawBoard();
        cout << "Player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move, try again.\n";
            i--;
            continue;
        }

        player_won = checkWin();
        if (player_won != 0) {
            drawBoard();
            cout << "Player " << player_won << " wins!\n";
            return;
        }
        
        switchPlayer();
    }

    drawBoard();
    cout << "It's a draw!\n";
}

int main() {
    char play_again;
    do {
        game();
        cout << "Do you want to play again? (Y/N): ";
        cin >> play_again;
    } while (play_again == 'Y' || play_again == 'y');

    return 0;
}
