#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#pragma once

using namespace std;

namespace coup{
class Player;

class Game{

    public:
    
     //private:
    vector<Player*> members;
    bool game_started = false;
    uint now_turn=0;
    bool first_time=true;
    void add_player(Player* player);

    vector<string> players();
    
    static string turn();
    
    string winner();
    Game(){
    
    }
    //find index of a name inside the player_list
    // uint find_index(const string& name){
    //     for(uint i=0; i<this->members.size(); i++){
    //         if(this->players()[i] == name){
    //             return i;
    //         }
    //     }
    //     return 0;
    // }
    

    void increase_index();
    

   
};

}






