#include <string>

class Game{
    private:
        std::string winner;
        std::string first_player;
        std::string second_player;
    protected:
        virtual void set_winner(const std::string& winner){ this->winner = winner;}

    public:
        Game(std::string first_player, std::string second_player){
            this->first_player = first_player;
            this->second_player = second_player;
        }
        virtual ~Game(){}
        virtual bool is_game_over() const = 0;
        virtual std::string get_winner() const{ return winner;}
        virtual void render() const = 0;
        
};