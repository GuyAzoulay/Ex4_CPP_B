#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Game.hpp"
uint global_turn = 0;
bool test =false;
const int nine = 9;
const int seven = 7;
namespace coup{
        
        void Player::income() {
            
            // cout<<this->game->players().size()<<":Player size"<<endl;
            //  cout<< global_turn<< ":Global turn"<<endl;
            //  cout<< this->find_index(this->name)<< ":Player index"<<endl;

            if(this->game->members.size() > 1 && this->is_alive){
               this->game->game_started =true; 
             
                if(global_turn == this->find_index(this->name)){
                    this->coin++;
                    this->last_move = "income";
                    this->game->increase_index();
                
                }
                else {
                
                    throw std::runtime_error("not your turn");
                    return;
                }
            }
            else{
                throw std::runtime_error("not enough players");
            }
          
        }
        void Player::foreign_aid() {
        //     cout<< " ---------------------" << endl;
        //   cout << "Global turn: " << global_turn << endl;
        //     cout << "Player index: " << this->find_index(this->name) << endl;
        //     cout<< " ---------------------" << endl;
            if(this->coins()>=0 && this->coins()<=nine&& this->game->members.size() > 1 &&global_turn == this->find_index(this->name)){
                this->last_move = "foreign_aid";
                this->coin += 2;
                this->game->increase_index();
            }
            else{
                throw std::runtime_error("Must coup!");
            }
        }


        void Player::coup(Player& target) {
            if(this->is_alive && target.is_alive){
               
            
            if(this->coins() >= seven){
                this->last_move = "coup";
                this->coin -= seven;
                target.is_alive = false;
                this->game->increase_index();
            }
            else{
                throw std::runtime_error("Not enough coins");
            }
            }
            else{
                throw std::runtime_error("You are dead");
            }
        }
        int Player::coins() const {
            return this->coin;
        }
        string Player::role(){
            return "";
        }
    
   
      
}
