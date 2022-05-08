//#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
//#include "Game.hpp"
#include "Duke.hpp"

namespace coup{
    void Duke::tax(){
        this->last_move = "tax";
        this->coin+=3;
        this->game->increase_index();
    }
    void Duke::block(Player &target){
      if(target.last_move == "foreign_aid"){
        target.coin -= 2;
      }
      else{
        throw std::runtime_error("Can only block foreign aid");
      }
    }
    string Duke::role(){
        return "Duke";
    }
}