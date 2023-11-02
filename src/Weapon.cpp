#include "../include/Weapon.hpp"

Weapon::Weapon(std::string name, int range, double weight){
    this->name = name;
    this->range = range;
    this->weight = weight;
}

std::string Weapon::getName(){
    return name;
}
int Weapon::getRange(){
    return range;
}
int Weapon::getWeight(){
    return weight;
}
void Weapon::setName(std::string newName){
    name = newName;
}
void Weapon::setRange(int newRange){
    range = newRange;
}
void Weapon::setWeight(double newWeight){
    weight = newWeight;
}