#include <iostream>
#include <vector>

void displayBoard(const std::vector<char>& board) {
    std::cout << "\n";
    for (int i = 0; i < 9; i++) {
        std::cout << " " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            std::cout << "\n";
            if (i < 6) std::cout << "---|---|---\n";
        } else {
            std::cout << "|";
        }
    }
    std::cout << "\n\n";
}

bool checkWin(const std::vector<char>& board, char player) {
    const int winningCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (auto& combo : winningCombos) {
        if (board[combo[0]] == player && board[combo[1]] == player && board[combo[2]] == player) {
            return true;
        }
    }
    return false;
}

bool isBoardFull(const std::vector<char>& board) {
    for (char cell : board) {
        if (cell == ' ') return false;
    }
    return true;
}

int main() {
    std::vector<char> board(9, ' ');
    char currentPlayer = 'X';
    int move;

    std::cout << "Willkommen zu Tic Tac Toe!" << std::endl;

    while (true) {
        displayBoard(board);
        std::cout << "Spieler " << currentPlayer << ", geben Sie Ihre Position (1-9) ein: ";
        std::cin >> move;

        if (move < 1 || move > 9 || board[move - 1] != ' ') {
            std::cout << "Ungültiger Zug! Versuchen Sie es erneut." << std::endl;
            continue;
        }

        board[move - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Spieler " << currentPlayer << " gewinnt!" << std::endl;
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            std::cout << "Unentschieden!" << std::endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    std::cout << "Drücken Sie die Eingabetaste, um das Programm zu beenden...";
    std::cin.ignore(); // Ignoriert eventuelle Reste im Eingabepuffer
    std::cin.get(); // Wartet auf Enter-Taste

    return 0;
}
