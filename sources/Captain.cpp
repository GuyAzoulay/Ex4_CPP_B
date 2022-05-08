
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Captain.hpp"

namespace coup{
    void Captain::steal(Player& target){
      if(global_turn == this->find_index(this->name)){
        this->last_move = "steal";
        if(target.coins() >=2){
          target.coin -= 2;
          this->coin += 2;
          this->steal_2 = true;
          this->stolen = &target;
          this->game->increase_index();
        
        }
        else if (target.coins() == 1){
          target.coin -= 1;
          this->coin += 1;
          this->steal_2 = true;
          this->stolen = &target;
          this->game->increase_index();        
        }
        else
        {
          throw std::runtime_error("Not enough coins");        
        }     
      }
      else
      {
        throw std::runtime_error("Not your turn");
      }
    }

    void Captain::block(Player& target){
      if(target.role() == "Captain"){
        if(dynamic_cast<Captain&>(target).steal_2)
        {
          dynamic_cast<Captain&>(target).stolen->coin += 2;
        }
        else if(dynamic_cast<Captain&>(target).steal_1)
        {
          dynamic_cast<Captain&>(target).stolen->coin += 1;
        }
      }
      else
      {
        throw std::runtime_error("Can only block captain");       
      }
    }
    string Captain::role(){
        return "Captain";
    }


}