#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"

using namespace std;
namespace coup{


class Duke : public Player{
    public:
    Duke(Game& game, const string &name) : Player(game, name){};
    void tax();
    static void block(Player &target); 
    string role() override;
};



}