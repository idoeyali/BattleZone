#include "common/games/tic_tac_toe/tic_tac_toe.hpp"
#include <iostream>
#include <cassert>

void test_valid_moves() {
    std::cout << "Testing valid moves...\n";
    TicTacToe game("Player 1", "Player 2");
    
    // Test valid moves
    game.make_move({0, 0, 'X'});
    game.make_move({1, 1, 'O'});
    game.make_move({2, 2, 'X'});
    
    // Test invalid moves
    try {
        game.make_move({0, 0, 'O'}); // Already occupied
        assert(false && "Should have thrown exception for occupied cell");
    } catch (const std::invalid_argument&) {
        std::cout << "✓ Caught invalid move (occupied cell)\n";
    }
    
    try {
        game.make_move({-1, 0, 'O'}); // Out of bounds
        assert(false && "Should have thrown exception for out of bounds");
    } catch (const std::invalid_argument&) {
        std::cout << "✓ Caught invalid move (out of bounds)\n";
    }
    
    std::cout << "Valid moves test passed!\n\n";
}

void test_win_conditions() {
    std::cout << "Testing win conditions...\n";
    
    // Test row win
    {
        TicTacToe game("Player 1", "Player 2");
        game.make_move({0, 0, 'X'});
        game.make_move({1, 0, 'O'});
        game.make_move({0, 1, 'X'});
        game.make_move({1, 1, 'O'});
        game.make_move({0, 2, 'X'});
        assert(game.is_game_over() && "Row win not detected");
        std::cout << "✓ Row win detected\n";
    }
    
    // Test column win
    {
        TicTacToe game("Player 1", "Player 2");
        game.make_move({0, 0, 'X'});
        game.make_move({0, 1, 'O'});
        game.make_move({1, 0, 'X'});
        game.make_move({1, 1, 'O'});
        game.make_move({2, 0, 'X'});
        assert(game.is_game_over() && "Column win not detected");
        std::cout << "✓ Column win detected\n";
    }
    
    // Test diagonal win
    {
        TicTacToe game("Player 1", "Player 2");
        game.make_move({0, 0, 'X'});
        game.make_move({0, 1, 'O'});
        game.make_move({1, 1, 'X'});
        game.make_move({1, 0, 'O'});
        game.make_move({2, 2, 'X'});
        assert(game.is_game_over() && "Diagonal win not detected");
        std::cout << "✓ Diagonal win detected\n";
    }
    
    // Test anti-diagonal win
    {
        TicTacToe game("Player 1", "Player 2");
        game.make_move({0, 2, 'X'});
        game.make_move({0, 1, 'O'});
        game.make_move({1, 1, 'X'});
        game.make_move({1, 0, 'O'});
        game.make_move({2, 0, 'X'});
        assert(game.is_game_over() && "Anti-diagonal win not detected");
        std::cout << "✓ Anti-diagonal win detected\n";
    }
    
    std::cout << "Win conditions test passed!\n\n";
}

void test_game_state() {
    std::cout << "Testing game state...\n";
    TicTacToe game("Player 1", "Player 2");
    
    // Test initial state
    assert(game.get_current_player() == "Player 1" && "Wrong initial player");
    std::cout << "✓ Initial player correct\n";
    
    // Test player switching
    game.make_move({0, 0, 'X'});
    assert(game.get_current_player() == "Player 2" && "Player not switched");
    std::cout << "✓ Player switching works\n";
    
    // Test game not over
    assert(!game.is_game_over() && "Game incorrectly marked as over");
    std::cout << "✓ Game state tracking works\n";
    
    std::cout << "Game state test passed!\n\n";
}

void test_board_rendering() {
    std::cout << "Testing board rendering...\n";
    TicTacToe game("Player 1", "Player 2");
    
    // Make some moves
    game.make_move({0, 0, 'X'});
    game.make_move({1, 1, 'O'});
    game.make_move({2, 2, 'X'});
    
    std::cout << "Current board state:\n";
    game.render();
    std::cout << "✓ Board rendered successfully\n\n";
}

int main() {
    // std::cout << "Starting Tic Tac Toe tests...\n\n";
    std::cout << "Running tests...\n";
    test_valid_moves();
    test_win_conditions();
    test_game_state();
    test_board_rendering();
    
    std::cout << "All tests passed successfully!\n";
    return 0;
} 