#pragma once

// Game-related enums and types
enum class GameType {
    TIC_TAC_TOE,
    ROCK_PAPER_SCISSORS,
    // TODO: Add more game types as needed
};

// Game-specific move types
struct TicTacToeMove {
    int row;
    int col;
    char symbol;  // 'X' or 'O'
};

enum RockPaperScissorsMove {
    ROCK,
    PAPER,
    SCISSORS
};