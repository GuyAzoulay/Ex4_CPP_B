#include "Game.hpp"
#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <stdio.h>
namespace coup{
        
        void Game::add_player(Player* player){
                const uint max_players = 6;
                if(this->members.size()<max_players && !this->game_started){
                       
                
                if(first_time){
                        global_turn = 0;
                        first_time = false;
                }
                
                this->members.push_back(player);
                this->now_turn++;
                player->is_alive = true;
                }
                else{
                        throw std::runtime_error("Too many players or too few players");
                }
        }
        vector<string> Game::players(){
                vector<string> names;
                for(uint i = 0; i < this->members.size(); i++){
                                // cout << i << ". "<<this->members[i]->name;
                                // cout << " , "<<this->members[i]->is_alive << endl;
                        if(this->members[i]->is_alive){
                                names.push_back(this->members[i]->name);
                        }
                }
             
                return names;
        }
        string Game::turn(){
                return "";
        }
        string Game::winner(){
                if(this->players().size() == 1 && this->game_started){
                        global_turn = 0;
                        return this->players()[0];
                }
                throw std::runtime_error("Must be more than 1 player!");
        }

        void Game::increase_index(){
               
                if(((global_turn + (uint)1 )% this->members.size()) == 0)
                {
                        global_turn = 0;
                        if(!this->members[global_turn]->is_alive){
                                global_turn++;
                        }
                }
                else
                {
                        if(this->members[global_turn+1]->is_alive)
                        {
                                global_turn++;        
                        }
                        else
                        {
                                global_turn++;
                                while(!this->members[global_turn]->is_alive)
                                {
                                        if(((global_turn + (uint)1 )% this->members.size()) == 0)
                                        {
                                                global_turn = 0;
                                        }
                                        else
                                        {
                                                cout << "TEST" << endl;
                                                global_turn++;
                                        }       
                                }
                        }
                }                   
        }
               
 
  
}