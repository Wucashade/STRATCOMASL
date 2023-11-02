#include "../include/MapEntity.hpp"

MapEntity::MapEntity(std::string name, int posX, int posY)
            :name(name), posX(posX), posY(posY){};

std::string MapEntity::getName(){
    return name;
}
int MapEntity::getPosX(){
    return posX;
}
int MapEntity::getPosY(){
    return posY;
}
void MapEntity::setName(std::string newName){
    name = newName;
}
void MapEntity::setPosX(int x){
    posX = x;
}
void MapEntity::setPosY(int y){
    posY = y;
}