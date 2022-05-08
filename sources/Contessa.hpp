#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Player.hpp"
using namespace std;

namespace coup{
class Contessa : public Player {

public:
    Contessa(Game& game, const string& name) : Player(game, name) {};
    static void block(Player &target) ;
    string role() override;
};

}


