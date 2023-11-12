#include "../include/Missile.hpp"

Missile::Missile(std::string name, int range, double weight, int posX, int posY, double speed)
                : Weapon(name, range, weight), posX(posX), posY(posY), speed(speed){

}

int Missile::getPosX(){
    return posX;
}

int Missile::getPosY(){
    return posY;
}

double Missile::getSpeed(){
    return speed;
}

void Missile::setPosX(int newPosX){
    posX = newPosX;
}

void Missile::setPosY(int newPosY){
    posY = newPosY;
}

void Missile::setSpeed(int newSpeed){
    speed = newSpeed;
}