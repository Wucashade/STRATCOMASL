#ifndef MISSILE_H
#define MISSILE_H

#include "../include/Weapon.hpp"

class Missile: public Weapon{
    public:
        Missile(std::string name, int range, double weight, int posX, int posY, double speed);
        ~Missile(){};

        void fly();

        int getPosX();
        int getPosY();
        double getSpeed();
        void setPosX(int newPosX);
        void setPosY(int newPosY);
        void setSpeed(int newSpeed);
        void moveMissile(){};


    private:

        int posX;
        int posY;
        double speed;
};

#endif