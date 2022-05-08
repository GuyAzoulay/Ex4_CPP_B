
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Captain.hpp"
#include "Ambassador.hpp"

namespace coup{

    void Ambassador::transfer(Player& first, Player& second) {
        if(first.coins() >0){
        this->last_move = "transfer";
        first.coin -= 1;
        second.coin += 1;
         this->game->increase_index();
        }
        else{
            throw std::runtime_error("Not enough coins");
        }
    }
    void Ambassador:: block(Player& target){
        if(target.role() == "Captain" && dynamic_cast<Captain&>(target).steal_2)
       {
             dynamic_cast<Captain&>(target).stolen->coin += 2;
             dynamic_cast<Captain&>(target).coin -= 2;
             dynamic_cast<Captain&>(target).steal_2 = false;
       }
        else if (target.role() == "Captain" && dynamic_cast<Captain&>(target).steal_1){
              dynamic_cast<Captain&>(target).stolen->coin += 1;
              dynamic_cast<Captain&>(target).coin -= 1;
              dynamic_cast<Captain&>(target).steal_1 = false;
        }
        else
        {
           throw std::runtime_error("Can only block captain");       
        }
    }
    string Ambassador::role(){
        return "Ambassador";
    }
    

}