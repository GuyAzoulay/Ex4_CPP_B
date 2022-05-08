#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"
using namespace std;

namespace coup{

class Ambassador : public Player{
    public:
    Ambassador(Game& game, const string &name) : Player(game, name){};
        void transfer(Player& first, Player& second);
    static void block(Player& target);
    string role() override;
};







}