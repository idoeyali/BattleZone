#include "../game.hpp"
#include <vector>
#include <string>
#include "../../types/game_types.hpp"

class TicTacToe : public Game{
    private:
        std::vector<std::vector<char>> board;
        std::string current_player;
        bool is_valid_move(const TicTacToeMove& move) const;
    public:
        TicTacToe(std::string first_player, std::string second_player);
        ~TicTacToe();
        bool is_game_over() const override;
bool is_board_full(bool &retFlag) const;
        void make_move(const TicTacToeMove& move);
        std::string get_current_player() const;
        void render() const override;
        

};
