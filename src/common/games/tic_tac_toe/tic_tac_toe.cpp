#include "tic_tac_toe.hpp"
#include <iostream>

TicTacToe::TicTacToe(std::string first_player, std::string second_player) : Game(first_player, second_player){
    board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
}
bool TicTacToe::is_game_over() const{
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') return true; // Row
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') return true; // Column
    }

    // Check diagonals
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') return true;
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') return true;

    return false;
}
void TicTacToe::make_move(const TicTacToeMove& move){
    if(is_valid_move(move)){
        board[move.row][move.col] = move.symbol;
    }
    else{
        throw std::invalid_argument("Invalid move");
    }
}
bool TicTacToe::is_valid_move(const TicTacToeMove& move) const{
    return move.row >= 0 && move.row < 3 && move.col >= 0 && move.col < 3 && board[move.row][move.col] == ' ';
}
std::string TicTacToe::get_current_player() const{
    return current_player;
}
void TicTacToe::render() const{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << board[i][j] << " ";
        }
    }
}
int main(){
    TicTacToe tic_tac_toe("Player 1", "Player 2");
    tic_tac_toe.make_move({0, 0, 'X'});
    tic_tac_toe.render();
    tic_tac_toe.make_move({1, 1, 'O'});
    tic_tac_toe.render();
    tic_tac_toe.make_move({2, 2, 'X'});
    tic_tac_toe.render();
}



