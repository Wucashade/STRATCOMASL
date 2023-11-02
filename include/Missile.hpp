#ifndef MISSILE_H
#define MISSILE_H

#include "../include/Weapon.hpp"

class Missile: public Weapon{
    public:
        Missile(std::string name, int range, double weight, int posX, int posY);
        ~Missile();

        int getPosX();
        int getPosY();
        void setPosX(int newPosX);
        void setPosY(int newPosY);


    private:

        int posX;
        int posY;
};

#endif