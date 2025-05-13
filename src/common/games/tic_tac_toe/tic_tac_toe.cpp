#include "tic_tac_toe.hpp"
#include <iostream>

TicTacToe::TicTacToe(std::string first_player, std::string second_player) : Game(first_player, second_player) {
    board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
    current_player = first_player;
}

TicTacToe::~TicTacToe() {
    // Destructor implementation
}

bool TicTacToe::is_game_over() const {
    bool retFlag;
bool retVal = is_board_full(retFlag);
if (retFlag) return retVal;
    
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') return true; // Row
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') return true; // Row
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') return true; // Column
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') return true; // Column
    }

    // Check diagonals
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') return true;
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') return true;
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') return true;
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') return true;


    return false;
}

bool TicTacToe::is_board_full(bool &retFlag) const
{
retFlag = true;
// Check if the board is full
    bool is_full = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                is_full = false;
                break;
            }
        }
    }

    if (is_full) return true;
retFlag = false;
return {};
}

void TicTacToe::make_move(const TicTacToeMove& move) {
    if(is_valid_move(move)) {
        board[move.row][move.col] = move.symbol;
    }
    else {
        throw std::invalid_argument("Invalid move");
    }
}

bool TicTacToe::is_valid_move(const TicTacToeMove& move) const {
    return move.row >= 0 && move.row < 3 && move.col >= 0 && move.col < 3 && board[move.row][move.col] == ' ';
}

std::string TicTacToe::get_current_player() const {
    return current_player;
}

void TicTacToe::render() const {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
} 



