#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"

using namespace std;

namespace coup{

class Captain : public Player{
    public:
    Captain(Game& game, const string &name) : Player(game, name){ };
    bool steal_1 = false;
    bool steal_2 = false;
    Player *stolen;
    void steal(Player& target);
    static void block(Player& target);
    string role() override;
};




}