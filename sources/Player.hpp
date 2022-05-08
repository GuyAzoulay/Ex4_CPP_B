#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Game.hpp"

#pragma once
using namespace std;
extern uint global_turn;
namespace coup{
    
    class Game;
    
    class Player{
        // try to add a variable which will held the less action of the player
            
        public:
       
        Game* game;
        //for tha assassin
  
       

        
        uint player_turn=0;
        uint player_index_game;
        bool is_alive=false;
        string last_move="";
       
        //////////////////
        int coin=0;
        string name;
        void income();
        void foreign_aid();
        virtual void coup(Player& target);
        int coins() const ;
        virtual string role();
        

        
       
    
    Player(Game& game, const string &name) {
        this->game = &game;
        this->name = name;
        game.add_player(this);
    
        
       
    }
    

    // find index of a name inside the player_list
    uint find_index(const string& name){
        for(uint i=0; i<this->game->members.size(); i++){
            if(this->game->members[i]->name == name){
                return i;
            }
        }
        return 0;
    }
    
    
};
}