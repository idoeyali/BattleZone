#pragma once
#include <string>

class Game {
protected:
    std::string player1;
    std::string player2;
    std::string current_player;

public:
    Game(std::string first_player, std::string second_player)
        : player1(first_player), player2(second_player), current_player(first_player) {}
    virtual ~Game() {}
    virtual bool is_game_over() const = 0;
    virtual void render() const = 0;
};