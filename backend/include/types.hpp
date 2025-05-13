#pragma once
#include <string>
#include <vector>

// Authentication
struct User {
  std::string userId;
  std::string username;
};

// Lobby
struct Lobby {
  std::string lobbyId;
  std::string name;
  std::vector<std::string> playerIds;
};

// Chat message
struct ChatMessage {
  std::string fromUserId;
  std::string text;
  std::string timestamp;
};

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

// …later: GameState, Move, etc.