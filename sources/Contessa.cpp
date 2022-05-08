//#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
//#include "Game.hpp"
#include "Contessa.hpp"
#include "Assassin.hpp"


namespace coup{

    void Contessa::block(Player& target){
   

      if(target.role()== "Assassin"){
        if(dynamic_cast<Assassin&>(target).coup_3){
         cout<<"coup3"<<endl;
          dynamic_cast<Assassin&>(target).couped->is_alive = true;
          dynamic_cast<Assassin&>(target).coup_3=false;

          
        }
        else if(dynamic_cast<Assassin&>(target).coup_7){

          dynamic_cast<Assassin&>(target).coup_7=false;
          throw std::runtime_error("Can only block assanation with 3 coins");
        }
        else{
          throw std::runtime_error("Can only block assanation with 3 coins");
        }
      }

      else{
        throw std::runtime_error("Can only block assassin");
      }
    
    }
    string Contessa::role(){
        return "Contessa";
    }
}