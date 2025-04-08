class Game{
    private:
        std::string current_player;
        std::string winner;
    protected:
        virtual bool is_valid_move(const std::string& move) const = 0;
        virtual void set_winner(const std::string& winner){ this->winner = winner;}
        virtual void set_current_player(const std::string& current_player){ this->current_player = current_player;}

    public:
        Game();
        virtual ~Game();
        virtual bool is_game_over() const = 0;
        virtual void make_move(const std::string& move) = 0;
        virtual std::string get_current_player() const{ return current_player;}
        virtual std::string get_winner() const{ return winner;}
        virtual void render() const = 0;
        
}