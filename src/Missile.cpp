#include "../include/Missile.hpp"

Missile::Missile(std::string name, int range, double weight, int posX, int posY)
                : Weapon(name, range, weight), posX(posX), posY(posY){

}

int Missile::getPosX(){
    return posX;
}

int Missile::getPosY(){
    return posY;
}

void Missile::setPosX(int newPosX){
    posX = newPosX;
}

void Missile::setPosY(int newPosY){
    posY = newPosY;
}