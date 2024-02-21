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

std::pair<int,int> Missile::getFrontPair(){
    if (!waypoints.empty()) {
            return waypoints.front();
    }

    throw std::runtime_error("Queue is empty");
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

void Missile::enqueueWaypoint(int x, int y){
    waypoints.push(std::make_pair(x, y));
}

void Missile::dequeueWaypoint() {
        if (!waypoints.empty()) {
            waypoints.pop();
        }
        throw std::runtime_error("Queue is empty"); 
}