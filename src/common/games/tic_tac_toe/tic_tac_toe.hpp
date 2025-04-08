class TicTacToe : public Game{
    private:
        std::vector<std::vector<std::string>> board;
    public:
        TicTacToe();
        ~TicTacToe();
        bool is_game_over() const override;
        void make_move(const std::string& move) override;
        std::string get_current_player() const override;
        std::string get_winner() const override;
        void render() const override;
        

}
