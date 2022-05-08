
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
#include "Assassin.hpp"
const int six =6;
const int three =3;
const int seven =7;
namespace coup{

    void Assassin::coup(Player& target){
        cout<<this->coup_3 << ":coup_3"<<endl;
        if(this->is_alive&& target.is_alive)
        { 
            if(this->coins() <= six && this->coins()>=three){
                this->last_move = "coup";
                this->coin -= 3;
 
                coup_3 = true;
                this->couped = &target;
                target.is_alive = false;
                this->game->increase_index();
            }
            else if(this->coins() >= seven)
            {   
            coup_7 = true;
            this->last_move = "coup";
            this->coin -= seven;
            target.is_alive = false;
            this->game->increase_index();
            }
            else 
            { 
                throw std::runtime_error("Not enough coins");
            }
        }
        else
        {
        throw std::runtime_error("Player is not alive");
        }
    }
    string Assassin::role(){
        return "Assassin";
    }
}