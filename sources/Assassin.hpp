#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"
using namespace std;

namespace coup{


class Assassin : public Player{
    public:
    Assassin(Game& game, const string &name) : Player(game, name){};
    void coup(Player& target) override;
    bool coup_3 = false;
    bool coup_7 = false;
    Player *couped;
    string role() override;
    
};


}